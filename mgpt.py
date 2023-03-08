import json

class Dictionary:
    def __init__(self, language):
        self.language = language
        self.words = {}

    def add_word(self, word, definitions):
        if word in self.words:
            self.words[word].extend(definitions)
        else:
            self.words[word] = definitions

    def update_word(self, word, definitions):
        self.words[word] = definitions

    def delete_word(self, word):
        if word in self.words:
            del self.words[word]

    def search_word(self, word):
        if word in self.words:
            return self.words[word]
        else:
            return None

    def save(self, dictionary):
        with open(dictionary, "w") as f:
            json.dump(self.__dict__, f)


class DictionaryApp:
    def __init__(self):
        self.dictionaries = {}

    def create_dictionary(self, language):
        self.dictionaries[language] = Dictionary(language)

    def add_word(self, language, word, definitions):
        if language in self.dictionaries:
            self.dictionaries[language].add_word(word, definitions)
        else:
            print("Dictionary not found")

    def update_word(self, language, word, definitions):
        if language in self.dictionaries:
            self.dictionaries[language].update_word(word, definitions)
        else:
            print("Dictionary not found")

    def delete_word(self, language, word):
        if language in self.dictionaries:
            self.dictionaries[language].delete_word(word)
        else:
            print("Dictionary not found")

    def search_word(self, language, word):
        if language in self.dictionaries:
            definitions = self.dictionaries[language].search_word(word)
            if definitions:
                print(f"{word}: {definitions}")
            else:
                print(f"{word} not found")
        else:
            print("Dictionary not found")

    def save_dictionary(self, language, dictionary):
        if language in self.dictionaries:
            self.dictionaries[language].save(dictionary)
        else:
            print("Dictionary not found")

    def load_dictionary(self, dictionary):
        with open(dictionary, "r") as f:
            data = json.load(f)
        language = data['language']
        dictionary = Dictionary(language)
        dictionary.words = data['words']
        self.dictionaries[language] = dictionary

    def print_menu(self):
        print("""
        1. Create dictionary
        2. Add word
        3. Update word
        4. Delete word
        5. Search word
        6. Save dictionary
        7. Quit
        """)

    def run(self):
        while True:
            self.print_menu()
            choice = input("Enter your choice: ")

            if choice == "1":
                language = input("Enter language: ")
                self.create_dictionary(language)
                continue
            elif choice == "2":
                language = input("Enter language: ")
                word = input("Enter word: ")
                definitions = input("Enter definitions separated by commas: ").split(",")
                self.add_word(language, word, definitions)
                continue
            elif choice == "3":
                language = input("Enter language: ")
                word = input("Enter word: ")
                definitions = input("Enter definitions separated by commas: ").split(",")
                self.update_word(language, word, definitions)
                continue
            elif choice == "4":
                language = input(("Enter language: "))
                word = input('Enter word you want to delete: ')
                self.dictionaries[language].delete_word(word)
                continue
            elif choice == '5':
                language = input(("Enter language: "))
                word = input('Enter the word, the interpretation of which you need to find: ')
                definitions = self.dictionaries[language].search_word(word)
                if definitions:
                    print(f'Interpretation of the word "{word}":')
                    for i, definition in enumerate(definitions):
                        print(f'{i + 1}. {definition}')
                else:
                    print(f'word  "{word}" nor found.')
                continue
            elif choice == "6":
                language = input(("Enter language: "))
                word = input("Enter the word you want to export: ")
                definitions = self.dictionaries[language].search_word(word)
                if definitions:
                    dictionary = f"{word}_definitions.txt"
                    with open(dictionary, "w") as file:
                        for definition in definitions:
                            file.write(definition + "\n")
                            print(f"word '{word}' and its interpretation were successfully exported to a file '{dictionary}'")
                        else:
                            print(f"word '{word}' not found.")
                continue

            elif choice == "7":
                print("Close program")
            break

main = DictionaryApp()
main.run()
