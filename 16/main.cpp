#include "input_16.h"

#include <algorithm>
#include <assert.h>
#include <iostream>
#include <numeric>
#include <variant>
#include <vector>

struct Packet
{
    unsigned int version;
    unsigned int typeId;
    std::variant<unsigned long long, std::vector<Packet>> content;

    unsigned int versionSum() const
    {
        unsigned int sum = version;
        if (const std::vector<Packet> *p = std::get_if<std::vector<Packet>>(&content))
        {
            const std::vector<Packet> &packets = *p;
            for (const auto &packet : packets)
            {
                sum += packet.versionSum();
            }
        }
        return sum;
    }

    unsigned long long value() const
    {
        if (typeId == 4)
        {
            return std::get<unsigned long long>(content);
        }
        const std::vector<Packet> &packets = std::get<std::vector<Packet>>(content);
        switch (typeId)
        {
        case 0:
            // sum
            return std::accumulate(std::begin(packets), std::end(packets), 0ull, [](unsigned long long sum, const Packet &packet)
                                   { return sum + packet.value(); });
        case 1:
            // product
            return std::accumulate(std::begin(packets), std::end(packets), 1ull, [](unsigned long long product, const Packet &packet)
                                   { return product * packet.value(); });
        case 2:
            // minimum
            return (*std::min_element(std::begin(packets), std::end(packets), [](const Packet &a, const Packet &b)
                                      { return a.value() < b.value(); }))
                .value();
        case 3:
            // maximum
            return (*std::max_element(std::begin(packets), std::end(packets), [](const Packet &a, const Packet &b)
                                      { return a.value() < b.value(); }))
                .value();
        case 5:
            return (packets[0].value() > packets[1].value() ? 1 : 0);
        case 6:
            return (packets[0].value() < packets[1].value() ? 1 : 0);
        case 7:
            return (packets[0].value() == packets[1].value() ? 1 : 0);
        default:
            assert(false && "should never get here!");
            return 0;
        }
    }
};

using Bits = std::vector<bool>;

Bits getBits()
{
    Bits bits;
    bits.reserve(input.size() * 4);
    for (char c : input)
    {
        if (c >= 'A')
        {
            c = c - 'A' + 10;
        }
        else
        {
            c -= '0';
        }
        for (int i = 3; i >= 0; --i)
        {
            bits.push_back((c & (1 << i)) != 0);
        }
    }
    return bits;
}

unsigned long long getNumber(Bits::const_iterator &iter, size_t nbBits)
{
    unsigned long long number = 0;
    for (int i = 0; i < nbBits; ++i, ++iter)
    {
        number = ((number << 1) | (*iter ? 1 : 0));
    }
    return number;
}
unsigned long long parseLiteral(Bits::const_iterator &iter)
{
    unsigned long long literal = 0;
    bool firstOfGroup;
    do
    {
        firstOfGroup = *iter++;
        literal = (literal << 4) + getNumber(iter, 4);
    } while (firstOfGroup);
    return literal;
}

Packet getPacket(Bits::const_iterator &iter)
{
    Packet packet;
    packet.version = static_cast<unsigned int>(getNumber(iter, 3));
    packet.typeId = static_cast<unsigned int>(getNumber(iter, 3));
    switch (packet.typeId)
    {
    case 4:
    {
        packet.content = parseLiteral(iter);
        break;
    }
    default:
    {
        packet.content = std::vector<Packet>();

        unsigned int lengthTypeId = *iter++;
        if (lengthTypeId == 0)
        {
            unsigned int totalLength = static_cast<unsigned int>(getNumber(iter, 15));
            Bits::const_iterator end = iter + totalLength;
            while (iter < end)
            {
                std::get<std::vector<Packet>>(packet.content).push_back(getPacket(iter));
            }
        }
        else
        {
            unsigned int nbSubPackets = static_cast<unsigned int>(getNumber(iter, 11));
            for (unsigned int i = 0; i < nbSubPackets; ++i)
            {
                std::get<std::vector<Packet>>(packet.content).push_back(getPacket(iter));
            }
        }
    }
    }
    return packet;
}

int main(int, char **)
{
    Bits bits = getBits();
    auto iter = bits.begin();
    Packet packet = getPacket(iter);

    unsigned int versionSum = packet.versionSum();
    unsigned long long value = packet.value();

    std::cout << "The sum of the versions is " << versionSum << std::endl;
    std::cout << "The value of the packet is " << value << std::endl;
}
