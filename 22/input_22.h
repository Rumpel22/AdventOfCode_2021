#pragma once
#include <utility>
#include <vector>

struct Instruction
{
    bool on;
    std::pair<int, int> x;
    std::pair<int, int> y;
    std::pair<int, int> z;
};

const std::vector<Instruction> instructions = {
    // {true, {10, 12}, {10, 12}, {10, 12}},
    // {true, {11, 13}, {11, 13}, {11, 13}},
    // {false, {9, 11}, {9, 11}, {9, 11}},
    // {true, {10, 10}, {10, 10}, {10, 10}},

    // {true, {-20, 26}, {-36, 17}, {-47, 7}},
    // {true, {-20, 33}, {-21, 23}, {-26, 28}},
    // {true, {-22, 28}, {-29, 23}, {-38, 16}},
    // {true, {-46, 7}, {-6, 46}, {-50, -1}},
    // {true, {-49, 1}, {-3, 46}, {-24, 28}},
    // {true, {2, 47}, {-22, 22}, {-23, 27}},
    // {true, {-27, 23}, {-28, 26}, {-21, 29}},
    // {true, {-39, 5}, {-6, 47}, {-3, 44}},
    // {true, {-30, 21}, {-8, 43}, {-13, 34}},
    // {true, {-22, 26}, {-27, 20}, {-29, 19}},
    // {false, {-48, -32}, {26, 41}, {-47, -37}},
    // {true, {-12, 35}, {6, 50}, {-50, -2}},
    // {false, {-48, -32}, {-32, -16}, {-15, -5}},
    // {true, {-18, 26}, {-33, 15}, {-7, 46}},
    // {false, {-40, -22}, {-38, -28}, {23, 41}},
    // {true, {-16, 35}, {-41, 10}, {-47, 6}},
    // {false, {-32, -23}, {11, 30}, {-14, 3}},
    // {true, {-49, -5}, {-3, 45}, {-29, 18}},
    // {false, {18, 30}, {-20, -8}, {-3, 13}},
    // {true, {-41, 9}, {-7, 43}, {-33, 15}},
    // {true, {-54112, -39298}, {-85059, -49293}, {-27449, 7877}},
    // {true, {967, 23432}, {45373, 81175}, {27513, 53682}},

    {true, {-44, 7}, {-48, -4}, {-28, 22}},
    {true, {-14, 37}, {-31, 23}, {-46, 0}},
    {true, {-2, 42}, {-40, 5}, {-15, 34}},
    {true, {-6, 40}, {-46, 8}, {-4, 43}},
    {true, {-14, 40}, {-22, 28}, {-39, 15}},
    {true, {-26, 18}, {-36, 18}, {-22, 24}},
    {true, {-1, 46}, {-14, 39}, {-6, 47}},
    {true, {-9, 43}, {-19, 35}, {3, 49}},
    {true, {-2, 49}, {-19, 35}, {-44, 9}},
    {true, {-14, 31}, {-31, 23}, {-15, 37}},
    {false, {-15, 0}, {10, 20}, {-1, 11}},
    {true, {-13, 39}, {-7, 40}, {-16, 29}},
    {false, {-36, -23}, {-22, -7}, {22, 32}},
    {true, {-42, 8}, {-27, 23}, {-24, 22}},
    {false, {30, 44}, {-6, 11}, {-25, -12}},
    {true, {-14, 37}, {-20, 31}, {-27, 19}},
    {false, {-11, 7}, {24, 39}, {-49, -36}},
    {true, {-40, 7}, {-46, 2}, {-8, 36}},
    {false, {-28, -9}, {9, 19}, {-3, 13}},
    {true, {-32, 19}, {-46, 4}, {-10, 35}},
    {true, {-57669, -47415}, {-34767, -16398}, {30569, 62270}},
    {true, {-26838, -18058}, {-44045, -32246}, {-69820, -54662}},
    {true, {23944, 45874}, {-56447, -36843}, {51476, 78050}},
    {true, {-60295, -37768}, {15477, 31617}, {-62436, -53796}},
    {true, {7279, 37283}, {-14827, 827}, {-81548, -71878}},
    {true, {14873, 45919}, {-55604, -29161}, {-73563, -62510}},
    {true, {8304, 25869}, {60634, 75835}, {-38723, -10959}},
    {true, {10010, 30443}, {-27861, -18913}, {75221, 96082}},
    {true, {-19174, 1724}, {-1716, 15662}, {-83027, -75955}},
    {true, {2933, 9957}, {51319, 54072}, {43068, 71431}},
    {true, {-54485, -38845}, {-59089, -33388}, {39472, 59916}},
    {true, {44991, 60045}, {39800, 52961}, {-50242, -11489}},
    {true, {29344, 48984}, {-12037, 3869}, {-80327, -68023}},
    {true, {-32654, 1023}, {30977, 64895}, {52313, 68196}},
    {true, {-61627, -36736}, {-16352, -227}, {59819, 74021}},
    {true, {-70800, -32442}, {-60912, -27524}, {-53014, -34685}},
    {true, {37172, 54896}, {-33170, -23103}, {39779, 62817}},
    {true, {33016, 45483}, {-29966, -21595}, {61920, 75220}},
    {true, {40062, 58134}, {-66288, -45661}, {-13163, 4407}},
    {true, {48899, 63190}, {-40057, -19858}, {-57642, -39508}},
    {true, {-13394, 5479}, {-33828, -8938}, {-81107, -59473}},
    {true, {-53077, -46727}, {26122, 44435}, {41182, 56258}},
    {true, {-882, 34139}, {72487, 90656}, {1449, 34384}},
    {true, {-55069, -25492}, {57603, 60372}, {27312, 37818}},
    {true, {11637, 35186}, {-2112, 35130}, {-82659, -58284}},
    {true, {-1963, 19390}, {31372, 43852}, {55664, 78279}},
    {true, {-37450, -13706}, {56862, 79450}, {42506, 58352}},
    {true, {-11194, 7926}, {-54868, -41855}, {59371, 69838}},
    {true, {-68076, -47918}, {-7134, 19211}, {54036, 59607}},
    {true, {56398, 65176}, {9373, 35857}, {-59779, -33781}},
    {true, {-29722, -13167}, {52154, 61111}, {34337, 71865}},
    {true, {-41452, -21137}, {38656, 58801}, {-74267, -49536}},
    {true, {29554, 32383}, {-16535, 13186}, {68589, 83493}},
    {true, {11565, 19985}, {-66635, -51018}, {40523, 55317}},
    {true, {-16115, 8224}, {-93747, -59306}, {-30707, -16928}},
    {true, {41464, 62560}, {28328, 43290}, {49899, 69729}},
    {true, {-78292, -62498}, {-26428, -963}, {33334, 43746}},
    {true, {-62268, -27494}, {52017, 78451}, {-27229, -9290}},
    {true, {74538, 81687}, {-6868, 9462}, {-42485, -7405}},
    {true, {-70139, -51493}, {33391, 58326}, {-47685, -18900}},
    {true, {-15600, -10169}, {-76996, -58016}, {26710, 50743}},
    {true, {-38135, -33369}, {-68467, -37987}, {-68299, -34906}},
    {true, {-32926, -12278}, {-17049, 5935}, {71187, 95480}},
    {true, {-68775, -38703}, {31347, 51664}, {-66756, -28690}},
    {true, {-17763, -444}, {-25060, -9321}, {-82848, -59956}},
    {true, {9259, 34670}, {-63918, -46717}, {-62805, -36148}},
    {true, {-38860, -17888}, {-83191, -60240}, {15932, 31388}},
    {true, {-27738, -12501}, {-58688, -48917}, {50240, 63344}},
    {true, {-9552, 12298}, {-82967, -63566}, {-31665, -8131}},
    {true, {-3262, 23176}, {-8404, -682}, {68987, 87074}},
    {true, {-492, 24054}, {76438, 84125}, {-3124, 15757}},
    {true, {-6636, 23517}, {24061, 51082}, {58265, 80778}},
    {true, {-11300, 13852}, {36935, 72289}, {54439, 75741}},
    {true, {-36722, -5253}, {38765, 48140}, {60050, 80209}},
    {true, {-68641, -42826}, {10138, 20406}, {-48840, -38994}},
    {true, {37946, 71780}, {-11716, -3224}, {-76794, -53565}},
    {true, {14937, 42416}, {-74948, -54941}, {17561, 31037}},
    {true, {-61298, -48316}, {21641, 32156}, {38100, 61810}},
    {true, {33337, 44565}, {-61197, -41116}, {-63088, -42095}},
    {true, {55485, 80696}, {-12185, 7524}, {38733, 61721}},
    {true, {19994, 48088}, {-63968, -29433}, {34529, 51173}},
    {true, {57918, 85515}, {-896, 14685}, {-34920, -21663}},
    {true, {-28290, -18544}, {-74670, -62248}, {-33511, -13509}},
    {true, {-91602, -59099}, {-28478, 5896}, {-22843, 268}},
    {true, {47808, 64741}, {-62234, -56202}, {-34499, -15875}},
    {true, {-5439, 29218}, {40801, 61745}, {-73755, -42460}},
    {true, {66499, 87188}, {-47632, -14352}, {-2835, 27458}},
    {true, {6077, 20827}, {59218, 81594}, {22627, 42843}},
    {true, {-76720, -44054}, {-58925, -27476}, {13431, 37577}},
    {true, {-67945, -52903}, {-59540, -48436}, {-3959, 28890}},
    {true, {63669, 81588}, {3522, 24426}, {-13019, 4078}},
    {true, {66389, 80203}, {7859, 36184}, {-21763, 5299}},
    {true, {8985, 37402}, {67471, 77806}, {23845, 39004}},
    {true, {-79912, -67840}, {11112, 26176}, {13492, 41306}},
    {true, {9298, 39655}, {49448, 70324}, {-53552, -37003}},
    {true, {5868, 25390}, {60778, 82461}, {-3147, 29756}},
    {true, {62208, 85012}, {24013, 43359}, {-4030, 20786}},
    {true, {25563, 60394}, {-77470, -53600}, {-24444, -10882}},
    {true, {-85136, -64905}, {9280, 27843}, {-24178, -13919}},
    {true, {-46556, -20968}, {61562, 77589}, {-55628, -32861}},
    {true, {56560, 95299}, {-33827, -18248}, {-5634, 1038}},
    {true, {-49836, -26941}, {-72556, -64453}, {-21395, -5169}},
    {true, {-15142, 1630}, {29424, 55194}, {-80676, -57685}},
    {true, {40758, 58341}, {-37580, -17953}, {47185, 63053}},
    {true, {-83532, -54519}, {14164, 37120}, {-8060, 28402}},
    {true, {12818, 44502}, {55987, 71453}, {-41223, -19473}},
    {true, {-4840, 2988}, {-65963, -42391}, {43719, 69256}},
    {true, {-17605, -5232}, {44129, 60456}, {-67226, -43598}},
    {true, {47446, 74934}, {-54664, -29117}, {12932, 43430}},
    {true, {55486, 76987}, {-56915, -46806}, {20053, 35664}},
    {true, {-32418, -5191}, {-89850, -69798}, {14068, 34962}},
    {true, {-67032, -37418}, {34844, 51405}, {33127, 59954}},
    {true, {-13655, 14693}, {-75994, -50458}, {-72104, -36662}},
    {true, {66339, 92744}, {-18657, -7726}, {21490, 33317}},
    {true, {53091, 73056}, {36859, 60782}, {14612, 29840}},
    {true, {-44743, -29546}, {41851, 61121}, {22465, 54041}},
    {true, {-9987, 1366}, {11297, 38316}, {68452, 83250}},
    {true, {-80587, -54313}, {18931, 30390}, {-48007, -36485}},
    {true, {-36867, -14328}, {40625, 54265}, {-74356, -41512}},
    {true, {15699, 30877}, {-70192, -46143}, {37310, 62324}},
    {true, {-71614, -38143}, {-41704, -16440}, {-66155, -38475}},
    {true, {-62484, -42887}, {-4231, 15340}, {-75961, -45592}},
    {true, {46006, 67614}, {26585, 47989}, {6308, 42157}},
    {true, {45024, 68068}, {-33616, 180}, {30942, 60664}},
    {true, {14301, 42992}, {44850, 66137}, {-62651, -38951}},
    {true, {-5142, 13215}, {-47989, -29881}, {-84658, -68851}},
    {true, {-15828, 12464}, {-85703, -72043}, {-26704, 414}},
    {true, {-85704, -48060}, {-49145, -21157}, {-29687, -11621}},
    {true, {-6374, 26062}, {-43479, -21489}, {-75304, -65078}},
    {true, {-65088, -40345}, {-70338, -44899}, {-30731, -18492}},
    {true, {-33236, -3437}, {-60726, -34937}, {-74647, -56493}},
    {true, {-89271, -55975}, {29143, 35214}, {-12958, 11803}},
    {true, {7570, 22211}, {-36457, -30528}, {-87550, -52770}},
    {true, {-21844, 7612}, {-13339, 3854}, {63591, 80571}},
    {true, {62681, 80087}, {-15165, -1484}, {-16312, 4733}},
    {true, {30764, 51898}, {-54770, -33399}, {-69113, -49263}},
    {true, {-14706, 3333}, {-34078, -20149}, {57303, 79672}},
    {true, {-57882, -46150}, {-2602, 5065}, {36801, 61301}},
    {true, {-6409, 4744}, {-23298, -4086}, {77909, 82727}},
    {true, {28231, 50858}, {-25112, 1285}, {-82337, -62613}},
    {true, {-60169, -35664}, {45331, 71566}, {-52986, -27989}},
    {true, {16548, 37232}, {29641, 41926}, {44045, 64175}},
    {true, {-27530, -5944}, {-54250, -41450}, {48642, 63840}},
    {true, {-33752, -18800}, {45216, 52417}, {-80150, -42007}},
    {true, {-46681, -39468}, {27115, 51324}, {41263, 68851}},
    {true, {-77564, -58032}, {1512, 31954}, {-29462, -6724}},
    {true, {25989, 54117}, {-22057, 7911}, {54881, 74834}},
    {true, {69655, 77091}, {-36962, -8338}, {-29623, -13034}},
    {true, {36547, 45906}, {-19538, -1870}, {54069, 80852}},
    {true, {48119, 58288}, {-6195, 22597}, {53580, 70770}},
    {true, {-79230, -45439}, {35671, 60446}, {-1874, 15269}},
    {true, {-8784, 1459}, {-31199, 64}, {70551, 83107}},
    {true, {1880, 12553}, {34951, 52913}, {66407, 90779}},
    {true, {-65227, -45109}, {-986, 23543}, {-56927, -41562}},
    {true, {38071, 55190}, {-1152, 16116}, {52049, 80225}},
    {true, {-48564, -33827}, {-53997, -37034}, {50494, 59423}},
    {true, {-3880, 15646}, {-95096, -58701}, {487, 15462}},
    {true, {32448, 44054}, {-61760, -31951}, {50025, 56984}},
    {true, {49465, 69635}, {-39603, -22099}, {-52151, -36714}},
    {true, {-75231, -49932}, {-60778, -54855}, {-26493, -5370}},
    {true, {35578, 48084}, {-69596, -41217}, {-55956, -28280}},
    {true, {-60448, -49199}, {52341, 68896}, {-6151, 12805}},
    {true, {-72886, -58561}, {-20435, 4228}, {25829, 48873}},
    {true, {-15783, -12488}, {-51668, -27553}, {-86556, -62238}},
    {true, {-62994, -42998}, {-80730, -58580}, {-3922, 18675}},
    {true, {-89876, -67328}, {-33822, -12798}, {-22322, 2742}},
    {true, {-43015, -21469}, {46582, 68250}, {-37517, -14243}},
    {true, {-32767, -11037}, {49857, 71371}, {15732, 34955}},
    {true, {2240, 21661}, {75578, 89677}, {3412, 23943}},
    {true, {31255, 50946}, {-41168, -11233}, {-77667, -54127}},
    {true, {32599, 65952}, {-35521, -10537}, {-56429, -50415}},
    {true, {-60138, -26615}, {-54582, -34921}, {31673, 49153}},
    {true, {-49673, -35379}, {-69100, -60235}, {-2394, 5510}},
    {true, {-36015, -13347}, {-12119, 14151}, {-91559, -66887}},
    {true, {-6323, 19724}, {-72320, -61811}, {33324, 65911}},
    {true, {17080, 26758}, {-67136, -36305}, {35911, 62171}},
    {true, {5223, 25662}, {-87359, -62299}, {23568, 38676}},
    {true, {-74373, -59477}, {-4295, 11346}, {36901, 64445}},
    {true, {-34299, -1928}, {11411, 25476}, {-91142, -75962}},
    {true, {-16791, 12614}, {-67861, -40449}, {-62621, -50416}},
    {true, {40128, 59229}, {48857, 75692}, {-51859, -21998}},
    {true, {-57970, -36216}, {-4627, 8697}, {57979, 63945}},
    {true, {24584, 35472}, {-54536, -26170}, {51165, 69055}},
    {true, {-8247, 15433}, {-36101, -14888}, {73892, 77781}},
    {true, {-64933, -48690}, {52625, 72716}, {19985, 44210}},
    {true, {-63835, -52109}, {-17596, -5749}, {-61623, -38639}},
    {true, {-3838, 6784}, {-72953, -58060}, {41661, 66294}},
    {true, {50897, 78898}, {-25992, -12109}, {-60442, -46049}},
    {true, {65788, 74812}, {-21111, -6276}, {10823, 46399}},
    {true, {-27607, -9446}, {34460, 63127}, {56809, 73065}},
    {true, {570, 34475}, {61988, 72741}, {-45705, -35924}},
    {true, {-17462, -8489}, {-8626, 8820}, {-84202, -61394}},
    {true, {-33944, -15274}, {-89456, -56691}, {-33904, -10998}},
    {true, {66413, 90344}, {-521, 34369}, {-41730, -11324}},
    {true, {-49505, -14224}, {48346, 60470}, {-65804, -32918}},
    {true, {-86096, -65120}, {17671, 43220}, {-3906, 30656}},
    {true, {33742, 44358}, {-19983, 821}, {58363, 74256}},
    {true, {68866, 75878}, {-34904, -11128}, {-44097, -23351}},
    {true, {2783, 19415}, {58410, 90714}, {-28778, -9588}},
    {true, {-75845, -59575}, {-46328, -31294}, {-26730, -5162}},
    {true, {28782, 29236}, {-70340, -61456}, {29839, 49236}},
    {true, {43385, 51055}, {31802, 51803}, {32252, 56629}},
    {true, {-14424, 5130}, {-69167, -53231}, {-59193, -37237}},
    {true, {4410, 29399}, {-86425, -68804}, {21060, 41858}},
    {true, {-76543, -49298}, {-1254, 13198}, {-62944, -31320}},
    {true, {58155, 76408}, {3385, 33072}, {27931, 49984}},
    {true, {53285, 68227}, {9528, 16970}, {38731, 70004}},
    {true, {-93183, -64817}, {25925, 48836}, {-21559, 11511}},
    {true, {41939, 75966}, {34833, 66872}, {5453, 22174}},
    {true, {-27905, -13907}, {66380, 77173}, {-30940, -2812}},
    {true, {-44965, -36722}, {44845, 61282}, {-56311, -30434}},
    {true, {-18507, 4231}, {51538, 82637}, {27243, 47809}},
    {true, {-22666, -8957}, {-70300, -61956}, {-54272, -23440}},
    {true, {-71598, -46251}, {40153, 63242}, {23221, 53691}},
    {true, {38505, 60525}, {-58882, -40951}, {14362, 23621}},
    {true, {-40771, -25170}, {60466, 77076}, {-26181, -3203}},
    {true, {48443, 70795}, {38515, 60309}, {-40023, -35935}},
    {true, {-64973, -51997}, {4324, 24699}, {-66495, -47350}},
    {true, {48357, 63912}, {24009, 51643}, {13119, 43197}},
    {true, {-59219, -45782}, {32426, 53977}, {-56899, -22839}},
    {false, {-82601, -62583}, {-29547, -19736}, {10012, 44278}},
    {false, {21881, 52715}, {-75462, -59619}, {-22352, 2451}},
    {false, {-45464, -31923}, {-84778, -57121}, {-36904, -20487}},
    {true, {-88151, -75143}, {-8134, 10815}, {11680, 22378}},
    {true, {-39971, -22009}, {-72573, -47306}, {-56516, -30255}},
    {false, {9322, 29654}, {-4082, 10417}, {-85840, -68364}},
    {false, {-72958, -39349}, {-62169, -48603}, {-38569, -2407}},
    {true, {6195, 28613}, {60609, 78035}, {-51100, -35991}},
    {true, {-18884, -2782}, {-56445, -48463}, {54414, 73962}},
    {false, {-34686, -14850}, {31925, 70449}, {-77698, -48963}},
    {true, {-50659, -28136}, {63604, 81082}, {2579, 9313}},
    {true, {5549, 35226}, {69786, 72274}, {-37289, -21739}},
    {false, {-29792, -6796}, {-81569, -63298}, {19068, 40723}},
    {false, {44836, 79546}, {-22779, 3568}, {-66800, -40145}},
    {false, {-49270, -30969}, {-3396, 25485}, {-78171, -59340}},
    {false, {35399, 60394}, {-68920, -56505}, {-1293, 13695}},
    {true, {-7191, -2494}, {-83630, -63883}, {33504, 51910}},
    {true, {-18980, -14896}, {65339, 79062}, {-18683, 1270}},
    {false, {43093, 61831}, {14636, 42577}, {-74949, -44384}},
    {true, {55863, 72523}, {-11248, 15275}, {40692, 55672}},
    {false, {49627, 71091}, {-31378, -15169}, {40187, 49905}},
    {true, {-71583, -61447}, {20612, 27406}, {-47136, -22936}},
    {false, {-22955, -508}, {-73996, -60313}, {16824, 51592}},
    {false, {-31772, -17942}, {3692, 29348}, {-81806, -61057}},
    {false, {-36116, -14323}, {-47112, -21136}, {71357, 88454}},
    {false, {39462, 69248}, {-67362, -37455}, {-46036, -22428}},
    {true, {-78767, -56235}, {-31380, -11432}, {19828, 51353}},
    {true, {-78645, -65106}, {10312, 37198}, {2401, 24591}},
    {true, {6402, 40318}, {-16548, 2555}, {73595, 84063}},
    {true, {-55615, -27722}, {49943, 68701}, {-28634, -4623}},
    {false, {42562, 67015}, {35610, 46866}, {34070, 42249}},
    {true, {8843, 44449}, {64895, 88067}, {18310, 35158}},
    {true, {52861, 75312}, {-17051, 2907}, {-53407, -21823}},
    {true, {-78385, -62728}, {-21841, 5253}, {-47028, -22568}},
    {true, {-10495, 14623}, {-80377, -59812}, {-34116, -22218}},
    {false, {-21996, -2742}, {37228, 50250}, {-71033, -60924}},
    {true, {56697, 77982}, {-7450, 3730}, {9771, 41652}},
    {false, {-67274, -50820}, {-5734, 5640}, {-56831, -37003}},
    {true, {11030, 31524}, {37918, 52771}, {-71435, -60852}},
    {true, {-83320, -65072}, {-32355, -11917}, {-26967, -18032}},
    {true, {-43677, -35148}, {-88398, -69549}, {-23854, 1908}},
    {true, {-49572, -38348}, {-46258, -17216}, {48043, 66417}},
    {true, {37384, 75100}, {-52354, -42729}, {-43047, -30541}},
    {false, {-53861, -35852}, {-5143, 18339}, {-83681, -51951}},
    {true, {-78236, -64745}, {2378, 20167}, {-40012, -25978}},
    {true, {34858, 54746}, {55821, 67805}, {-6400, 20512}},
    {false, {-82598, -70040}, {12999, 27880}, {-28265, -20266}},
    {false, {36133, 50921}, {57912, 79306}, {-24361, -3945}},
    {true, {21170, 43558}, {59657, 62681}, {32050, 47374}},
    {false, {67304, 92012}, {-38797, -25594}, {-17070, -7453}},
    {true, {-24303, 243}, {-38622, -26360}, {62498, 80626}},
    {true, {-35395, -1784}, {55251, 80783}, {-27257, -8718}},
    {true, {21761, 37471}, {42320, 78924}, {-57570, -23254}},
    {false, {51236, 81636}, {-15056, 9704}, {-62783, -46651}},
    {true, {24630, 41162}, {-80403, -63498}, {-31775, -7958}},
    {true, {-43744, -26951}, {47013, 67420}, {-29814, -8102}},
    {true, {26603, 63444}, {-12214, 8779}, {65219, 82907}},
    {true, {51940, 73971}, {-74860, -42866}, {-13886, 17671}},
    {true, {-92209, -76808}, {-10855, 14855}, {7758, 11786}},
    {false, {8207, 16724}, {-67090, -50961}, {43285, 49532}},
    {true, {-22397, -2482}, {62603, 88589}, {-33214, -12265}},
    {false, {-78419, -62461}, {-21534, -2157}, {32108, 35955}},
    {true, {-24006, 12481}, {4449, 20019}, {-81599, -71932}},
    {true, {-40605, -13896}, {-47711, -16365}, {-79247, -53064}},
    {true, {832, 22273}, {61218, 82893}, {-44519, -40600}},
    {false, {-29620, -13977}, {-78751, -54304}, {27369, 60011}},
    {false, {-14823, 10317}, {1880, 32923}, {-92955, -62132}},
    {true, {54354, 71905}, {-60825, -35957}, {-30727, -24555}},
    {true, {-33573, -29143}, {-72142, -60601}, {4256, 27173}},
    {false, {41652, 57462}, {3208, 37256}, {37000, 58096}},
    {true, {-30305, -14266}, {-69805, -63510}, {-50479, -23537}},
    {true, {-49741, -29481}, {19079, 42387}, {60359, 80724}},
    {true, {10590, 22833}, {44189, 59294}, {46046, 66234}},
    {false, {27431, 42490}, {-53997, -34542}, {52456, 80995}},
    {true, {53221, 89449}, {6997, 28317}, {-44585, -14492}},
    {true, {46562, 65116}, {-54532, -37162}, {-56535, -32017}},
    {true, {-42384, -12585}, {-70810, -55699}, {45949, 64203}},
    {false, {-77739, -63412}, {-41149, -14305}, {27531, 47698}},
    {true, {10915, 16415}, {-80296, -72044}, {-36080, -7043}},
    {false, {64883, 97215}, {8011, 22409}, {-7746, 5012}},
    {false, {41971, 72613}, {35196, 51812}, {-44437, -29568}},
    {true, {-43711, -23568}, {-70680, -54720}, {-40601, -34077}},
    {true, {-16542, 1141}, {52444, 82672}, {43901, 59221}},
    {false, {-68205, -59516}, {-32644, -18560}, {38606, 52974}},
    {false, {61892, 64269}, {-1452, 11550}, {43516, 54626}},
    {true, {-9354, 26205}, {-95112, -73796}, {-12420, -2002}},
    {true, {68603, 88449}, {14846, 32027}, {-37275, -5964}},
    {false, {53228, 69887}, {-46772, -36524}, {4431, 20570}},
    {false, {-51220, -43549}, {22283, 39913}, {-64534, -43506}},
    {true, {57172, 86360}, {-26130, -709}, {16305, 39032}},
    {true, {-17848, 14974}, {46246, 58941}, {-67550, -46292}},
    {false, {58035, 63691}, {14876, 34764}, {26962, 57547}},
    {true, {-75787, -51262}, {-49064, -29353}, {16029, 20922}},
    {true, {-4894, 14726}, {-17046, 5889}, {72075, 84493}},
    {false, {33532, 47782}, {-76307, -52222}, {-48923, -17755}},
    {true, {-13391, -5303}, {48245, 70668}, {-63779, -49431}},
    {true, {-58930, -43507}, {20362, 43248}, {48151, 71704}},
    {true, {70149, 92770}, {-9541, 10644}, {-6635, 28810}},
    {true, {31210, 64948}, {-48006, -21611}, {40652, 55871}},
    {true, {-28823, -7281}, {-9742, 2492}, {-84876, -66370}},
    {false, {-19166, -9817}, {-80319, -52505}, {-47786, -27118}},
    {true, {17602, 27875}, {13530, 26359}, {60440, 89349}},
    {true, {-45705, -19841}, {56915, 86069}, {4943, 32642}},
    {false, {68005, 81155}, {-29765, -16005}, {-25061, -14900}},
    {true, {-65261, -52679}, {-66447, -52070}, {-28901, -7919}},
    {false, {-82161, -52284}, {-22502, 9835}, {-63314, -33804}},
    {false, {-18121, -15979}, {-54614, -31740}, {51026, 63778}},
    {true, {-73676, -54888}, {-49297, -18394}, {27558, 33489}},
    {true, {28721, 54510}, {-10030, -1313}, {-79605, -49555}},
    {false, {11053, 31767}, {-32845, -23247}, {-80025, -56672}},
    {true, {-68386, -51398}, {27015, 53165}, {31825, 40319}},
    {true, {-7540, 22589}, {59320, 83712}, {-35089, -28351}},
    {false, {-48223, -32176}, {35378, 59272}, {-66955, -50598}},
    {false, {-25574, -10518}, {27418, 50238}, {-79559, -52513}},
    {true, {19175, 51407}, {-26995, -9229}, {66692, 72533}},
    {false, {-63090, -36602}, {16243, 43718}, {46820, 75911}},
    {true, {-18516, -9233}, {-48055, -28188}, {-82976, -60569}},
    {false, {14759, 44490}, {-10730, 11648}, {56458, 82559}},
    {true, {23455, 40535}, {15420, 27229}, {-84600, -55189}},
    {true, {-48299, -36541}, {50431, 73592}, {-19144, -1839}},
    {false, {-81344, -55459}, {20930, 46304}, {-9345, 14558}},
    {true, {47196, 65637}, {30426, 47615}, {-30228, -18046}},
    {false, {58163, 83551}, {8867, 26974}, {-35873, -11226}},
    {false, {6270, 22771}, {37387, 57400}, {36092, 57663}},
    {false, {-35106, -25204}, {5350, 15478}, {63386, 77636}},
    {true, {47160, 59650}, {-51193, -34124}, {10503, 49733}},
    {true, {-14789, 3340}, {60278, 88977}, {28007, 46842}},
    {false, {-6624, 12635}, {-83183, -52792}, {29941, 60688}},
    {false, {-26353, -19359}, {-78917, -53187}, {-49653, -42601}},
    {true, {-87135, -47727}, {-10772, 8106}, {35265, 44532}},
    {true, {-88740, -70750}, {-217, 15347}, {12806, 29839}},
    {false, {31685, 53283}, {-81911, -47577}, {-25086, -18921}},
    {true, {46622, 69887}, {-46629, -9525}, {-50166, -42612}},
    {false, {-15867, 1880}, {-98763, -72090}, {-5368, 10111}},
    {true, {-5912, 22381}, {9151, 27498}, {-80071, -60569}},
    {true, {8192, 15221}, {73577, 81728}, {-14163, 6679}},
    {true, {-22509, 4222}, {20798, 51576}, {55267, 78530}},
    {true, {-7460, 16881}, {51061, 76312}, {31500, 60109}},
    {false, {63978, 80332}, {-46479, -21214}, {17724, 27861}},
    {false, {-48142, -29566}, {-768, 38252}, {63177, 77599}},
    {false, {-22352, -3879}, {-67212, -37828}, {-78347, -41751}},
    {true, {61414, 72961}, {-45257, -28247}, {-33471, -19631}},
    {true, {-43526, -12688}, {57160, 75937}, {9029, 28586}},
    {true, {11342, 37138}, {46690, 59578}, {38233, 55140}},
    {false, {13515, 32899}, {47202, 66072}, {47086, 57782}},
    {true, {-19540, 6334}, {-56308, -35255}, {-77753, -55523}},
    {true, {-41925, -12451}, {61066, 74500}, {-26647, -15757}},
    {true, {60674, 79986}, {-30792, -1210}, {-57275, -33857}},
    {false, {-18884, -7353}, {23448, 56271}, {62374, 74763}},
    {true, {-44386, -15359}, {25414, 46534}, {-74182, -51840}},
    {true, {-36711, -20755}, {-67230, -45754}, {-56326, -24885}},
    {true, {72018, 96153}, {16522, 29738}, {-11147, 2054}},
    {true, {5973, 29852}, {55283, 72301}, {42944, 57136}},
    {false, {-50246, -27653}, {49043, 67875}, {24129, 45399}},
    {true, {-22284, -17636}, {21285, 32831}, {65161, 74363}},
    {false, {7735, 17847}, {48454, 54584}, {-60291, -42384}},
    {true, {56449, 93303}, {12556, 20734}, {-38611, -8545}},
    {false, {46038, 71965}, {-31095, -14977}, {-53091, -36186}},
    {true, {53210, 73760}, {18116, 23448}, {12649, 33378}},
    {false, {-83782, -50786}, {325, 30910}, {36498, 55449}},
    {true, {-11837, 13836}, {-82566, -60770}, {-30914, -11896}},
    {false, {-13846, 7560}, {72, 21588}, {68481, 86336}},
    {false, {-25685, -4603}, {29212, 57708}, {-65410, -60517}},
    {false, {-79113, -60386}, {26862, 39241}, {-4353, 29483}},
    {false, {-19892, 6771}, {51449, 72628}, {23897, 52090}},
    {false, {-71828, -53222}, {28667, 43977}, {25709, 37388}},
    {false, {28972, 50612}, {2418, 33040}, {-75017, -49640}},
    {false, {-23546, 3296}, {68489, 75275}, {-33316, -23806}},
    {false, {-46386, -30181}, {9760, 24029}, {57523, 67908}},
    {true, {-56316, -28882}, {48428, 62993}, {-48907, -32191}},
    {true, {-19707, -779}, {-73947, -40756}, {31616, 69601}},
    {false, {37761, 59827}, {6067, 16149}, {51785, 66336}},
    {true, {30923, 48572}, {52049, 72728}, {10493, 16555}},
    {true, {-26538, 1937}, {-81450, -56187}, {23729, 60276}},
    {false, {-48465, -28004}, {-90311, -56997}, {-9574, 25785}},
    {false, {-47377, -28389}, {-52506, -37609}, {-57507, -36160}},
    {true, {-36148, -24926}, {-64369, -51420}, {-69537, -38270}},
    {false, {62650, 82366}, {-28917, 8638}, {44805, 55648}},
    {false, {28149, 41757}, {43594, 62806}, {-38133, -32521}},
    {true, {-60752, -36491}, {38751, 61565}, {-48382, -36761}},
    {false, {64344, 99438}, {-18208, 4375}, {-22825, -5665}},
    {true, {-51669, -27629}, {50339, 66867}, {-41498, -24192}},
    {false, {25105, 40249}, {62440, 67046}, {21785, 49918}},
    {true, {58750, 91053}, {10035, 24848}, {-42659, -12650}},
    {false, {-84762, -59511}, {-24289, 1942}, {9634, 24955}},
    {true, {-94933, -68735}, {-17490, 292}, {-1579, 16250}},
    {false, {-78894, -60509}, {-40495, -5011}, {32059, 62300}},
    {false, {12870, 39008}, {55250, 64944}, {-51208, -30118}},
    {true, {2754, 21460}, {-38868, -392}, {-93705, -64934}},
    {true, {18042, 31269}, {-47061, -19873}, {52410, 82608}},
    {true, {29379, 68201}, {-51515, -41233}, {-45509, -34262}},
    {false, {52671, 84684}, {-16898, 5471}, {37071, 45630}},
    {true, {-98677, -68218}, {-20295, 4826}, {5421, 30729}},
    {false, {-49508, -22500}, {-2847, 20414}, {-69003, -50843}},
    {true, {-95062, -74272}, {9248, 21864}, {-22635, 1951}},
    {true, {7542, 29789}, {-48009, -23225}, {-85578, -64378}},
    {false, {-45405, -37229}, {-83374, -62547}, {-17446, 8556}},
    {false, {-45880, -27014}, {72506, 92343}, {-5157, 1778}},
    {true, {-30115, -2925}, {52679, 71889}, {-68644, -48667}},
    {true, {-76029, -52766}, {-54478, -30765}, {-46175, -28566}},
};