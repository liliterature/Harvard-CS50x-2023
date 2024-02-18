def main():
    text = input("Text: ")
    l = count_characters(text) * 100 / count_words(text)
    s = count_sentences(text) * 100 / count_words(text)
    grade = round(0.0588 * l - 0.296 * s - 15.8)

    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


def count_characters(text):
    sum = 0
    for c in text:
        if c.isalnum():
            sum += 1
    return sum


def count_words(text):
    return text.count(' ') + 1


def count_sentences(text):
    return text.count('.') + text.count('!') + text.count('?')

main()
