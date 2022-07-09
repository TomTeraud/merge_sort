#include <stdio.h>
#include <cs50.h>

const int amount = 5;
int nrs[amount] = {5, 4, 3, 1, 9};


//const int amount = 32;
//int nrs[amount] = {207, 206, 205, 204, 203, 202, 201, 109, 108, 107, 106, 105, 104, 103, 102, 101, 207, 206, 205, 204, 203, 202, 201, 109, 108, 107, 106, 105, 104, 103, 102, 101};

// const int amount = 16;
// int nrs[amount] = {150, 140, 130, 120, 110, 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 160};

// const int amount = 10;
// int nrs[amount] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

// const int amount = 10;
// int nrs[amount] = {8, 7, 6, 5, 4, 3, 11, 2, 1, 9,};


//const int amount = 12;
//int nrs[amount] = {12, 13, 8, 7, 6, 5, 4, 3, 11, 2, 1, 9};

//const int amount = 4;
//int nrs[amount] = {18, 13, 16, 17};

//const int amount = 6;
//int nrs[amount] = {6, 5, 4, 3, 2, 1};

bool merge_active = false;
int tmp[amount];

bool sort_numbers( bool nrs_tmp, int l_index, int m_index, int h_index);

int main(void)
{
    int array_size = amount;
    printf("Before sort: \n");
    for (int i = 0; i < array_size; i++)
    {
        printf("%i, ", nrs[i]);
    }
    printf("\n");

    int low, midle, high;
    bool nrs_to_tmp = false;
    low = 0;
    high = array_size - 1;
    midle = 0;
    // call sort_nrs
    nrs_to_tmp = sort_numbers(nrs_to_tmp, low, midle, high);

    if (!nrs_to_tmp)
    {
        for (int i = 0; i < array_size; i++)
        {
            nrs[i] = tmp[i];
        }
    }


    printf("\n");
    printf("\nAfter sort:\n");
    for (int i = 0; i < array_size; i++)
    {
        printf("%i, ", nrs[i]);
    }
    printf("\n");
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

bool sort_numbers( bool nrs_tmp, int l_index, int m_index, int h_index)
{
    if (merge_active)
        {
            // swich arrays
            nrs_tmp = ((nrs_tmp + 1) % 2);
        }
    // base case
    if (l_index >= h_index)
    {
        if (!merge_active)
        {
            merge_active = true;
            return true;
        }
        else
        {
            nrs_tmp = ((nrs_tmp + 1) % 2);
            return nrs_tmp;
        }
    }
    //config next level array element indexes nrs[index]


        // setup new next level array midle point.
        int size = (h_index - l_index) + 1;
        int odd = 0;
        if ((size % 2) != 0)
        {
            m_index = l_index + ((size - 1) / 2) - 1;
            odd = 1;
        }
        else
        {
            m_index = l_index + (size / 2) - 1;
        }


    //call for low half of given array
    nrs_tmp = sort_numbers( nrs_tmp,                  l_index, m_index, m_index);
    // array correcting
    if (odd == 1)
    {
        for (int i = 0; i < (h_index - m_index); i++)
        {
            tmp[m_index + 1 + i] = nrs[m_index + 1 + i];
        }
        odd = 0;
    }
    //call for high half of given array
    nrs_tmp = sort_numbers( nrs_tmp,                  m_index + 1, m_index, h_index);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// start merge back arrays
    //merged nr counters
    int lmc = 0;
    int hmc = 0;
    for (int i = 0; i < size; i = (lmc + hmc))
    {
        //copy values from nrs array to tmp array if true
        //copy values from tmp array to nrs array if false
        if (nrs_tmp)
        {
        //choose smalest value first
            //chose element from array before middle
            if (((nrs[l_index + lmc] < nrs[m_index + 1 + hmc]) && lmc < (h_index - m_index) && lmc != ((m_index - l_index) + 1) ) || hmc == (h_index - m_index))
            {
                tmp[l_index + lmc + hmc] = nrs[l_index + lmc];
                lmc++;
            }
            //chose element from array after middle
            else
            {
                tmp[l_index + lmc + hmc] = nrs[m_index + 1 + hmc];
                hmc++;
            }
        }
        else
        {
            //chose element from array before middle
            if (((tmp[l_index + lmc] < tmp[m_index + 1 + hmc]) && lmc < (h_index - m_index) && lmc != ((m_index - l_index) + 1)) || hmc == (h_index - m_index))
            {
                nrs[l_index + lmc + hmc] = tmp[l_index + lmc];
                lmc++;
            }
            //chose element from array after middle
            else
            {
                nrs[l_index + lmc + hmc] = tmp[m_index + 1 + hmc];
                hmc++;
            }
        }
    }
    // swich arrays
    nrs_tmp = ((nrs_tmp + 1) % 2) ;
    return nrs_tmp;
}
