from csv import reader, DictReader
from sys import argv

# main method
def main():
    # validate entry input
    if len(argv) < 3:
        print("usage error, dna.py sequence.txt database.csv")
        exit()

    # store it in a string
    dna = get_dna_list(argv[2])

    # dictionary to store the sequences we will count
    sequences = {}

    # extract the sequences from the database into a list
    with open(argv[1]) as peoplefile:
        people = reader(peoplefile)
        for row in people:
            dnaSequences = row
            dnaSequences.pop(0)
            break

    # copy the list in a dictionary, the genes are the keys
    for item in dnaSequences:
        sequences[item] = 1

    # iterate trough the dna sequence, when it finds repetitions of the values from sequence dictionary it counts them
    for key in sequences:
        l = len(key)
        tempMax = 0
        temp = 0
        for i in range(len(dna)):
            # after counting a sequence it skips at the end of it to avoid counting twice
            while temp > 0:
                temp -= 1
                continue

            # if the segment of dna corresponds to the key and there is a repetition of it we start counting
            if dna[i: i + l] == key:
                while dna[i - l: i] == dna[i: i + l]:
                    temp += 1
                    i += l

                # it compares the value to the previous longest sequence and if it is longer it overrides it
                if temp > tempMax:
                    tempMax = temp

        # store the longest sequences in the dictionary using the correspondent key
        sequences[key] += tempMax

    # open and iterate trough the database of people treating each one like a dictionary so it can compare to the sequences one
    with open(argv[1], newline='') as peoplefile:
        people = DictReader(peoplefile)
        for person in people:
            match = 0
            # compares the sequences to every person, prints the name before leaving the program if there is a match founded
            for dna in sequences:
                if sequences[dna] == int(person[dna]):
                    match += 1
            if match == len(sequences):
                print(person['name'])
                exit()
        # no match founded
        print("No match")

# method to read the dna sequence from the file
def get_dna_list(dna_file_input):
    # read the dna sequence from the file
    with open(dna_file_input) as dna_file:
        dna_reader = reader(dna_file)
        for row in dna_reader:
            dna_list = row

    # return the first element in the list
    return dna_list[0]

main()
