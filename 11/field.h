#pragma once
#include <assert.h>
#include <array>
#include <vector>

template <size_t height, size_t width, typename T = int>
class Field
{
public:
    using Neighbours = std::vector<T *>;
    static constexpr size_t height = height;
    static constexpr size_t width = width;

    Field(std::initializer_list<T> data_)
    {
        assert(data.size() == height * width);

        std::copy(std::begin(data_), std::end(data_), std::begin(data));
    }

    T &get(size_t x, size_t y)
    {
        return data[y * width + x];
    }

    Neighbours getNeighbours(size_t x, size_t y)
    {
        Neighbours neighbours{};
        if (x > 0)
        {
            neighbours.push_back(&get(x - 1, y));
            if (y > 0)
            {
                neighbours.push_back(&get(x - 1, y - 1));
            }
            if (y < height - 1)
            {
                neighbours.push_back(&get(x - 1, y + 1));
            }
        }
        if (x < width - 1)
        {
            neighbours.push_back(&get(x + 1, y));
            if (y > 0)
            {
                neighbours.push_back(&get(x + 1, y - 1));
            }
            if (y < height - 1)
            {
                neighbours.push_back(&get(x + 1, y + 1));
            }
        }
        if (y > 0)
        {
            neighbours.push_back(&get(x, y - 1));
        }
        if (y < height - 1)
        {
            neighbours.push_back(&get(x, y + 1));
        }
        return neighbours;
    }

private:
    std::array<T, height * width> data;
};
