import csv
import sys


def main():
    # python dna.py databases/small.csv sequences/1.txt
    # Bob

    # TODO: Check for command-line usage
    dnafile = sys.argv[1]
    dnatxt = sys.argv[2]
    rows = []

    # TODO: Read database file into a variable
    with open(dnafile) as file:
        reader = csv.DictReader(file)
        for row in reader:
            rows.append(row)

    # TODO: Read DNA sequence file into a variable
    with open(dnatxt) as file:
        se = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    STR = []
    for i in range(1, len(reader.fieldnames)):
        STR.append(longest_match(se, reader.fieldnames[i]))

    # TODO: Check database for matching profiles
    for row in rows:
        value = list(row.values())
        value1 = [int(x) for x in value[1:]]
        if value1 == STR:
            print(value[0])
            break
    else:
        print('No match')


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
