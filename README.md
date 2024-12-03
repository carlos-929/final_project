CineRank - Movie Sorting Application


Overview:
CineRank is a Windows Forms application that demonstrates and compares the performance of Quick Sort and Merge Sort algorithms on movie data. The application allows users to sort movies by average ratings or titles, with real-time performance analytics.


Prerequisites:
Visual Studio || .NET Framework 4.7.2 or later || C++/CLI support for Visual Studio || Windows Forms development components


Required extensions (available throught Visual Studio Installer):
C++ Windows Forms for VS 2022 (.NET Framework) || C++/WinRT templates and visualizer for VS 2022


Setup Instructions:
1. Clone the repository or download the source code
2. Required Data Files:
   Place movies.csv and ratings.csv in the project directory
   These files should be in the same directory as the executable


4. Opening the Project:
   Open Visual Studio 2022
   Navigate to File -> Open -> Project/Solution
   Select the .vcsproj file


5. Build Configuration
   Build -> Build Solution (F6)
   Resolve and dependencies if prompted


Running the Application:
1. Start the application using F5 (Debug) or Ctrl+F% (Run without Debug)
2. Using the Interface:
   Click "Load Data" to import movie and ratings data
   Select sorting algorithm (Quick Sort or Merge Sort)
   Choose sorting criteria (Average or Title)
   Select sort direction (Ascending or Descending)
   View performance analytics using the Analytics button


Features:
1. Data Loading and Processing:
   Reads and parses CSV files
   Calculates average ratings
   Displays progress during data loading


2. Sorting Options:
   Quick Sort implementation
   Merge Sort implementation
   Sort by average rating or title
   Ascending/descending options


3. Performance Analytics:
   Real-time duration measurements
   Comparison between algorithms
   Performance data visualization


Troubleshooting:
1. Data Loading Issues:
   Ensure CSV files are present in the correct directory
   Check file permissions
   Verify CSV format matches expected structure


2. Build Errors:
   Verity Visual Studio extensions are installed
   Check .NET Framework version
   Ensure C++/CLI support is enables


3. Runtime Issues:
   Check Windows Forms components are installed
   Verify memory availability for large datasets
   Enable debug logging if needed


Development Notes:
The application uses STL vectors for data management || Custom comparators handle different sorting criteria || Performance metrics are collected using the chrono library || GUI updates are managed through Windows Forms events


Project Structure:
CineRank/
|--Source Files/
|  |--Form1.h                # Main form header
|  |--Form1.cpp              # Form implementation
|  |--AssemblyInfo.cpp       # Assembly information
|  |--pch.h                  # Precomplied header
|
|--Resource Files/
|  |--app.rc                 # Application resources
|
|--Data Files/
   |--movies.csv             # Movie data
   |--ratings.csv            # Rating data


Authors:
Alex Andujar || Carlos Vasquez || Juan Ponce


Acknowledgments:
MovieLens dataset || Visual Studio development tools || Windows Forms framework
