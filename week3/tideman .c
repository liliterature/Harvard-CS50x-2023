#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count = 0;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);
void mergesort(pair arr[], int len);
void merge(pair arr[], pair l[], int llen, pair r[], int rlen);
bool creates_cycle(int winner, int loser);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]] += 1;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
    return;
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    // TODO
    /*
    pair temp;
    streng = preferences[pairs[i].winner][pairs[i].loser] - preferences[pairs[j].winner][pairs[j].loser];
        if (streng < 0)
    {
        temp = pairs[i];
        pairs[i] = pairs[j];
        pairs[j] = temp;
    }
    */
    mergesort(pairs, pair_count);
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    // TODO
    for (int i = 0; i < pair_count; i++)
    {
        if (!creates_cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }
    return;
}

// Print the winner of the election
void print_winner(void)
{
    // TODO
    for (int i = 0; i < candidate_count; i++)
    {
        int loser = 0;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i])
            {
                loser = 1;
                break;
            }
        }
        if (!loser)
        {
            printf("%s\n", candidates[i]);
            break;
        }
    }
    return;
}

// merge sort
void mergesort(pair arr[], int len)
{
    if (len <= 1)
    {
        return;
    }
    int mid = len / 2;
    pair l[mid];
    pair r[len - mid];
    for (int i = 0; i < mid; i++)
    {
        l[i] = arr[i];
    }
    for (int j = mid; j < len; j++)
    {
        r[j - mid] = arr[j];
    }
    mergesort(l, mid);
    mergesort(r, len - mid);
    merge(arr, l, mid, r, len - mid);
}

void merge(pair arr[], pair l[], int llen, pair r[], int rlen)
{
    int i = 0, j = 0, k = 0;
    while (i < llen && j < rlen)
    {
        int streng = preferences[l[i].winner][l[i].loser] - preferences[r[j].winner][r[j].loser];
        if (streng > 0)
        {
            arr[k] = l[i];
            i++;
        }
        else if (streng < 0)
        {
            arr[k] = r[j];
            j++;
        }
        else
        {
            arr[k] = l[i];
            i++;
            k++;
            arr[k] = r[j];
            j++;
        }
        k++;
    }
    while (i < llen)
    {
        arr[k] = l[i];
        i++;
        k++;
    }
    while (j < rlen)
    {
        arr[k] = r[j];
        j++;
        k++;
    }
}

// cycle
bool creates_cycle(int winner, int loser)
{
    if (winner == loser)
    {
        return true;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[loser][i])
        {
            if (creates_cycle(winner, i))
            {
                return true;
            }
        }
    }
    return false;
}
