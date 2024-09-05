The program allows users to input team data, save it to a file, and perform an analysis to find teams with specific characteristics, such as the youngest, shortest, or lightest teams.

## Features

- **Team Data Input**: Users can input team data such as team name, competition name, number of participants, average age, height, and weight.
- **Data Storage**: The inputted data is stored in an internal structure and can be displayed in a memo field for review.
- **Save Data to File**: The program can save all entered team data to a text file for later use.
- **Data Analysis**: The program analyzes the data to find teams with minimal average age, height, and weight, displaying the results to the user.

## Structure Overview

### `Tstud` Structure

The program uses a `Tstud` structure to store information about each team. The structure contains the following fields:

- `kr`: Team name
- `ko`: Competition name
- `pip`: Additional information
- `n`: Team number
- `vi`: Average age of participants
- `r`: Average height of participants
- `va`: Average weight of participants

The program uses two arrays of this structure:
- `st[100]`: Stores information about all teams.
- `stmin[100]`: Stores teams with minimal characteristics (used for analysis).

## How It Works

### 1. Adding Team Data

When a user inputs team data, the `TForm1::BitBtn1Click` method saves the data to the `st[]` array. The entered data is also displayed in `Memo1` for easy visualization.

### 2. Saving Data to a File

The `TForm1::Button1Click` method allows the user to save all entered team data to a file named `Sportyvni_zmagannya.text`. Each team's data is written to the file, with fields separated by spaces.

### 3. Analyzing Team Data

The `TForm1::Button3Click` method analyzes the data by:
- Checking for duplicate teams (based on `kr` and `ko`).
- Summing and averaging the parameters (age, height, weight) for teams with the same name.
- Identifying and displaying the teams with the minimum average age, height, and weight in `Memo2`.

The results include:
- "Youngest team"
- "Shortest team"
- "Lightest team"
