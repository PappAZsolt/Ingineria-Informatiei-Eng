import time
import random

def random_event(score):
    events = [
        ("Penalty! You lose 1 point.",-1),
        ("Bonus!, You gain 1 point", +1),
        ("No change!", 0)
    ]
    event = random.choice(events)
    print("\nRandom Event: ", event[0])
    return max(score + event[1],0)



def ask_question(question, options, correct_option):
    print("\n" + question)
    for i, option in enumerate(options):
        print(f"{i + 1}. {option}")
    try:
        answer = int(input("Your answer (1-4): "))
        return answer == correct_option
    except ValueError:
        return False


def main():
    print("Welcome to the Quiz Game!")
    score = 0
    questions = {
        "easy": [
            ("What is Python?", ["A type of snake", "A programming language", "A fruit", "A car"], 2),
            ("What is 2+2?", ["3", "4", "5", "6"], 2),
            ("What is the capital of France?", ["Berlin", "London", "Paris", "Madrid"], 3),
        ],
        "medium": [
            
            ("Which of the following can `sorted()` be applied to?", 
             ["Only lists", "Lists and dictionaries", "Any iterable", "Only numerical data"], 3),
            ("What sorting algorithm does Python's `sorted()` use?", 
             ["Bubble sort", "Merge Sort", "TimSort", "Quick Sort"], 3),
        ],
        "hard":[
            ("Messi or Ronaldo?", ["Messi", "Ronaldo","Messi","Messi"], 2),
            ("What is the time complexity of Python's `sorted()` in the worst case?", 
             ["O(n)", "O(n log n)", "O(n^2)", "O(log n)"], 2),
        ]
    }
    questions = (
        random.sample(questions["easy"], len(questions["easy"])) +
        random.sample(questions["medium"], len(questions["medium"])) +
        random.sample(questions["hard"], len(questions["hard"]))
    )

    for i, (question, options, correct_option) in enumerate(questions, 1):
        print(f"\nQuestion {i}/{len(questions)}")
        if ask_question(question, options, correct_option):
            print("Correct! \U0001F600")
            score += 1
        else:
            print("Wrong answer. \U0001F641")
        
        score = random_event(score)

        time.sleep(1)

    print(f"\nGame Over! Your final score is {score}/{len(questions)}")

if __name__ == "__main__":
    main()


# introduce random events(ex: loose 2 points for a random penalty)
# add levels of difficulty progression