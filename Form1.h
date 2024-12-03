#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <chrono>
#include <functional>
#include <algorithm>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace CppCLRWinFormsProject {

    struct Movie
    {
        int movieId;
        std::string title;
        std::string genres;
    };

    struct Rating
    {
        int userID;
        int movieId;
        float rating_value;
    };

    struct Movie_Average
    {
        std::string title;
        int movieId;
        float average;
    };
    struct SortAnalytics {
        std::string algorithm;
        std::string criteria;
        std::string order;
        long long duration;
    };

    bool compareAverageAscending(const Movie_Average& a, const Movie_Average& b);
    bool compareAverageDescending(const Movie_Average& a, const Movie_Average& b);
    bool compareTitleAscending(const Movie_Average& a, const Movie_Average& b);
    bool compareTitleDescending(const Movie_Average& a, const Movie_Average& b);

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void)
        {
            InitializeComponent();

            movies = new std::vector<Movie>();
            ratings = new std::vector<Rating>();
            movie_averages = new std::vector<Movie_Average>();


           
            isQuickSortSelected = false;
            isMergeSortSelected = false;
            isAscending = true;
            isSortedByAverage = true;

            // Add event handlers
            this->loadDataButton->Click += gcnew System::EventHandler(this, &Form1::loadDataButton_Click);
            this->quickSortButton->Click += gcnew System::EventHandler(this, &Form1::quickSortButton_Click);
            this->mergeSortButton->Click += gcnew System::EventHandler(this, &Form1::mergeSortButton_Click);
            this->ascendentButton->Click += gcnew System::EventHandler(this, &Form1::ascendentButton_Click);
            this->descendentButton->Click += gcnew System::EventHandler(this, &Form1::descendentButton_Click);
            this->resetButton->Click += gcnew System::EventHandler(this, &Form1::resetButton_Click);
            this->analyticsButton->Click += gcnew System::EventHandler(this, &Form1::analyticsButton_Click);
            this->sortCriteriaComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::sortCriteriaComboBox_SelectedIndexChanged);

            
            this->sortCriteriaComboBox->SelectedIndex = 0; // Default to Sort by Average
        }

    protected:
        ~Form1()
        {
            if (components)
            {
                delete components;
            }

            delete movies;
            delete ratings;
            delete movie_averages;


        }

    private:
        System::ComponentModel::Container^ components;

        // Controls
        Panel^ headerPanel;
        Button^ resetButton;
        Panel^ buttonsPanel;
        Button^ quickSortButton;
        Button^ mergeSortButton;
        Button^ ascendentButton;
        Button^ descendentButton;
        Button^ loadDataButton;
        ProgressBar^ loadDataProgressBar;
        Button^ analyticsButton;
        DataGridView^ dataGridView1;
        ComboBox^ sortCriteriaComboBox;

        // En la inicialización de los controles
        DataGridView^ analyticsGridView;

       


        // Member variables
        std::vector<Movie> *movies;
        std::vector<Rating> *ratings;
        std::vector<Movie_Average> *movie_averages;

        bool isQuickSortSelected;
        bool isMergeSortSelected;
        bool isAscending;
        bool isSortedByAverage;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->headerPanel = (gcnew System::Windows::Forms::Panel());
            this->resetButton = (gcnew System::Windows::Forms::Button());
            this->buttonsPanel = (gcnew System::Windows::Forms::Panel());
            this->quickSortButton = (gcnew System::Windows::Forms::Button());
            this->mergeSortButton = (gcnew System::Windows::Forms::Button());
            this->ascendentButton = (gcnew System::Windows::Forms::Button());
            this->descendentButton = (gcnew System::Windows::Forms::Button());
            this->loadDataButton = (gcnew System::Windows::Forms::Button());
            this->loadDataProgressBar = (gcnew System::Windows::Forms::ProgressBar());
            this->analyticsButton = (gcnew System::Windows::Forms::Button());
            this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
            this->sortCriteriaComboBox = (gcnew System::Windows::Forms::ComboBox());

            this->headerPanel->SuspendLayout();
            this->buttonsPanel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
            this->SuspendLayout();

            // 
            // headerPanel
            // 
            this->headerPanel->BackColor = System::Drawing::SystemColors::ControlDark;
            this->headerPanel->Controls->Add(this->resetButton);
            this->headerPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->headerPanel->Location = System::Drawing::Point(0, 0);
            this->headerPanel->Name = L"headerPanel";
            this->headerPanel->Size = System::Drawing::Size(1406, 60);
            this->headerPanel->TabIndex = 0;
            // 
            // resetButton
            // 
            this->resetButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->resetButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->resetButton->Location = System::Drawing::Point(10, 10);
            this->resetButton->Name = L"resetButton";
            this->resetButton->Size = System::Drawing::Size(100, 40);
            this->resetButton->TabIndex = 0;
            this->resetButton->Text = L" Reset";
            this->resetButton->UseVisualStyleBackColor = true;
            // 
            // buttonsPanel
            // 
            this->buttonsPanel->BackColor = System::Drawing::SystemColors::ControlLight;
            this->buttonsPanel->Controls->Add(this->sortCriteriaComboBox);
            this->buttonsPanel->Controls->Add(this->analyticsButton);
            this->buttonsPanel->Controls->Add(this->loadDataProgressBar);
            this->buttonsPanel->Controls->Add(this->loadDataButton);
            this->buttonsPanel->Controls->Add(this->descendentButton);
            this->buttonsPanel->Controls->Add(this->ascendentButton);
            this->buttonsPanel->Controls->Add(this->mergeSortButton);
            this->buttonsPanel->Controls->Add(this->quickSortButton);
            this->buttonsPanel->Dock = System::Windows::Forms::DockStyle::Top;
            this->buttonsPanel->Location = System::Drawing::Point(0, 60);
            this->buttonsPanel->Name = L"buttonsPanel";
            this->buttonsPanel->Size = System::Drawing::Size(1406, 100);
            this->buttonsPanel->TabIndex = 1;
            // 
            // quickSortButton
            // 
            this->quickSortButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->quickSortButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->quickSortButton->Location = System::Drawing::Point(10, 10);
            this->quickSortButton->Name = L"quickSortButton";
            this->quickSortButton->Size = System::Drawing::Size(130, 40);
            this->quickSortButton->TabIndex = 0;
            this->quickSortButton->Text = L" Quick Sort";
            this->quickSortButton->UseVisualStyleBackColor = true;
            // 
            // mergeSortButton
            // 
            this->mergeSortButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->mergeSortButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->mergeSortButton->Location = System::Drawing::Point(150, 10);
            this->mergeSortButton->Name = L"mergeSortButton";
            this->mergeSortButton->Size = System::Drawing::Size(130, 40);
            this->mergeSortButton->TabIndex = 1;
            this->mergeSortButton->Text = L" Merge Sort";
            this->mergeSortButton->UseVisualStyleBackColor = true;
            // 
            // ascendentButton
            // 
            this->ascendentButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->ascendentButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->ascendentButton->Location = System::Drawing::Point(290, 10);
            this->ascendentButton->Name = L"ascendentButton";
            this->ascendentButton->Size = System::Drawing::Size(130, 40);
            this->ascendentButton->TabIndex = 2;
            this->ascendentButton->Text = L" Ascendent";
            this->ascendentButton->UseVisualStyleBackColor = true;
            // 
            // descendentButton
            // 
            this->descendentButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->descendentButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->descendentButton->Location = System::Drawing::Point(430, 10);
            this->descendentButton->Name = L"descendentButton";
            this->descendentButton->Size = System::Drawing::Size(130, 40);
            this->descendentButton->TabIndex = 3;
            this->descendentButton->Text = L" Descendent";
            this->descendentButton->UseVisualStyleBackColor = true;
            // 
            // loadDataButton
            // 
            this->loadDataButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->loadDataButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->loadDataButton->Location = System::Drawing::Point(570, 10);
            this->loadDataButton->Name = L"loadDataButton";
            this->loadDataButton->Size = System::Drawing::Size(130, 40);
            this->loadDataButton->TabIndex = 4;
            this->loadDataButton->Text = L" Load Data";
            this->loadDataButton->UseVisualStyleBackColor = true;
            // 
            // loadDataProgressBar
            // 
            this->loadDataProgressBar->Location = System::Drawing::Point(710, 20);
            this->loadDataProgressBar->Name = L"loadDataProgressBar";
            this->loadDataProgressBar->Size = System::Drawing::Size(200, 20);
            this->loadDataProgressBar->Style = System::Windows::Forms::ProgressBarStyle::Marquee;
            this->loadDataProgressBar->TabIndex = 5;
            this->loadDataProgressBar->Visible = false; // Initially hidden
            // 
            // analyticsButton
            // 
            this->analyticsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->analyticsButton->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->analyticsButton->Location = System::Drawing::Point(930, 10);
            this->analyticsButton->Name = L"analyticsButton";
            this->analyticsButton->Size = System::Drawing::Size(130, 40);
            this->analyticsButton->TabIndex = 6;
            this->analyticsButton->Text = L" Analytics";
            this->analyticsButton->UseVisualStyleBackColor = true;
            // 
            // sortCriteriaComboBox
            // 
            this->sortCriteriaComboBox->Location = System::Drawing::Point(1070, 20);
            this->sortCriteriaComboBox->Name = L"sortCriteriaComboBox";
            this->sortCriteriaComboBox->Size = System::Drawing::Size(200, 24);
            this->sortCriteriaComboBox->TabIndex = 7;
            this->sortCriteriaComboBox->Items->Add("Sort by Average");
            this->sortCriteriaComboBox->Items->Add("Sort by Title");
            // 
            // dataGridView1
            // 
            this->dataGridView1->AllowUserToAddRows = false;
            this->dataGridView1->AllowUserToDeleteRows = false;
            this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {
                (gcnew System::Windows::Forms::DataGridViewTextBoxColumn()),
                    (gcnew System::Windows::Forms::DataGridViewTextBoxColumn())
            });
            this->dataGridView1->Location = System::Drawing::Point(50, 180);
            this->dataGridView1->Name = L"dataGridView1";
            this->dataGridView1->ReadOnly = true;
            this->dataGridView1->RowHeadersWidth = 51;
            this->dataGridView1->RowTemplate->Height = 24;
            this->dataGridView1->Size = System::Drawing::Size(800, 650);
            this->dataGridView1->TabIndex = 2;
            // Configure columns
            (safe_cast<System::Windows::Forms::DataGridViewTextBoxColumn^>(this->dataGridView1->Columns[0]))->HeaderText = L"TITLE MOVIE";
            (safe_cast<System::Windows::Forms::DataGridViewTextBoxColumn^>(this->dataGridView1->Columns[0]))->Name = L"titleMovieColumn";
            (safe_cast<System::Windows::Forms::DataGridViewTextBoxColumn^>(this->dataGridView1->Columns[1]))->HeaderText = L"AVERAGE";
            (safe_cast<System::Windows::Forms::DataGridViewTextBoxColumn^>(this->dataGridView1->Columns[1]))->Name = L"averageColumn";
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1000, 650);
            this->Controls->Add(this->dataGridView1);
            this->Controls->Add(this->buttonsPanel);
            this->Controls->Add(this->headerPanel);
            this->Name = L"Form1";
            this->Text = L"Final Project";
            this->headerPanel->ResumeLayout(false);
            this->buttonsPanel->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
            this->ResumeLayout(false);

            
            this->analyticsGridView = (gcnew System::Windows::Forms::DataGridView());
            this->analyticsGridView->AllowUserToAddRows = false;
            this->analyticsGridView->AllowUserToDeleteRows = false;
            this->analyticsGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
            this->analyticsGridView->Columns->Add("Algorithm", "Algorithm");
            this->analyticsGridView->Columns->Add("Criteria", "Criteria");
            this->analyticsGridView->Columns->Add("Order", "Order");
            this->analyticsGridView->Columns->Add("Duration", "Duration (ms)");
            this->analyticsGridView->Location = System::Drawing::Point(650, 145);
            this->analyticsGridView->Name = L"analyticsGridView";
            this->analyticsGridView->ReadOnly = true;
            this->analyticsGridView->Size = System::Drawing::Size(500, 525);
            this->Controls->Add(this->analyticsGridView);
        }
#pragma endregion

    private:
        
        System::Void loadDataButton_Click(System::Object^ sender, System::EventArgs^ e) {

           
            this->loadDataProgressBar->Visible = true;

         
            std::ifstream file("movies.csv");

            if (!file.is_open())
            {
                MessageBox::Show("Error: Could not open movies.csv!");
                return;
            }
            else
            {
                MessageBox::Show("Success: Could open movies.csv!");
            }

            std::string line;
            movies->clear();

         
            std::getline(file, line);

            auto start1 = std::chrono::high_resolution_clock::now();

            while (std::getline(file, line))
            {
                std::stringstream ss(line);
                std::string movieIdStr, title, genres;

                // Parse CSV fields
                std::getline(ss, movieIdStr, ',');
                std::getline(ss, title, ',');
                std::getline(ss, genres, ',');

                // Create a Movie object and add it to the vector
                Movie movie;
                movie.movieId = std::stoi(movieIdStr);
                movie.title = title;
                movie.genres = genres;
                movies->push_back(movie);
            }

            auto end1 = std::chrono::high_resolution_clock::now();
            auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1);

            MessageBox::Show("Movies.csv reading time: " + duration1.count().ToString() + " ms");

            file.close();

           
            std::ifstream file2("ratings.csv");

            if (!file2.is_open())
            {
                MessageBox::Show("Error: Could not open ratings.csv!");
                return;
            }
            else
            {
                MessageBox::Show("Success: Could open ratings.csv!");
            }

            std::string lineRatings;
            ratings->clear();
            movie_averages->clear();

            
            std::getline(file2, lineRatings);

            while (std::getline(file2, lineRatings))
            {
                std::stringstream ss2(lineRatings);
                std::string userID, movie_ID, rating_s;

                
                std::getline(ss2, userID, ',');
                std::getline(ss2, movie_ID, ',');
                std::getline(ss2, rating_s, ',');

                
                Rating rating;
                rating.userID = std::stoi(userID);
                rating.movieId = std::stoi(movie_ID);
                rating.rating_value = std::stof(rating_s);
                ratings->push_back(rating);
            }

            file2.close();

            // Calculate average ratings
            auto start_calc = std::chrono::high_resolution_clock::now();

            for (const Movie& movie : *movies)
            {
                Movie_Average mov_ave;
                mov_ave.title = movie.title;

                float sum = 0;
                int counter = 0;

                for (const Rating& rating : *ratings)
                {
                    if (rating.movieId == movie.movieId)
                    {
                        counter++;
                        sum += rating.rating_value;
                    }
                }

                if (counter > 0)
                    mov_ave.average = sum / (float)counter;
                else
                    mov_ave.average = 0.0;

                mov_ave.movieId = movie.movieId;
                movie_averages->push_back(mov_ave);
            }

            auto end_calc = std::chrono::high_resolution_clock::now();
            auto duration_calc = std::chrono::duration_cast<std::chrono::milliseconds>(end_calc - start_calc);

            MessageBox::Show("Average ratings calculation time: " + duration_calc.count().ToString() + " ms");

            // Hide the progress bar
            this->loadDataProgressBar->Visible = false;

            // Update DataGridView
            updateDataGridView();
        }

     
        System::Void quickSortButton_Click(System::Object^ sender, System::EventArgs^ e) {
            isQuickSortSelected = true;
            isMergeSortSelected = false;

         
            quickSortButton->BackColor = System::Drawing::Color::LightBlue;
            mergeSortButton->BackColor = System::Drawing::SystemColors::Control;

            // Perform sorting if data is loaded
            if (!movie_averages->empty())
            {
                sortData();
                updateDataGridView();
            }
        }

       
        System::Void mergeSortButton_Click(System::Object^ sender, System::EventArgs^ e) {
            isQuickSortSelected = false;
            isMergeSortSelected = true;

          
            mergeSortButton->BackColor = System::Drawing::Color::LightBlue;
            quickSortButton->BackColor = System::Drawing::SystemColors::Control;

            // Perform sorting if data is loaded
            if (!movie_averages->empty())
            {
                sortData();
                updateDataGridView();
            }
        }

       
        System::Void ascendentButton_Click(System::Object^ sender, System::EventArgs^ e) {
            isAscending = true;

        
            ascendentButton->BackColor = System::Drawing::Color::LightBlue;
            descendentButton->BackColor = System::Drawing::SystemColors::Control;

          
            if (!movie_averages->empty())
            {
                sortData();
                updateDataGridView();
            }
        }

        // Event handler for Descendent button
        System::Void descendentButton_Click(System::Object^ sender, System::EventArgs^ e) {
            isAscending = false;


            descendentButton->BackColor = System::Drawing::Color::LightBlue;
            ascendentButton->BackColor = System::Drawing::SystemColors::Control;

        
            if (!movie_averages->empty())
            {
                sortData();
                updateDataGridView();
            }
        }

     
        System::Void sortCriteriaComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
            if (this->sortCriteriaComboBox->SelectedIndex == 0)
            {
                isSortedByAverage = true;
            }
            else
            {
                isSortedByAverage = false;
            }

        
            if (!movie_averages->empty())
            {
                sortData();
                updateDataGridView();
            }
        }

    
        System::Void resetButton_Click(System::Object^ sender, System::EventArgs^ e) {
          
            isQuickSortSelected = false;
            isMergeSortSelected = false;
            isAscending = true;
            isSortedByAverage = true;

         
            quickSortButton->BackColor = System::Drawing::SystemColors::Control;
            mergeSortButton->BackColor = System::Drawing::SystemColors::Control;
            ascendentButton->BackColor = System::Drawing::SystemColors::Control;
            descendentButton->BackColor = System::Drawing::SystemColors::Control;

           
            movies->clear();
            ratings->clear();
            movie_averages->clear();

           
            this->dataGridView1->Rows->Clear();
        }

     

       
        void updateDataGridView()
        {
           
            this->dataGridView1->Rows->Clear();

         
            for (const Movie_Average& mov_ave : *movie_averages)
            {
                String^ title = gcnew String(mov_ave.title.c_str());
                String^ average = mov_ave.average.ToString("F2");

                this->dataGridView1->Rows->Add(title, average);
            }
        }

        System::Void analyticsButton_Click(System::Object^ sender, System::EventArgs^ e) {
            if (movie_averages->empty()) {
                MessageBox::Show("No data loaded to analyze!");
                return;
            }

            std::vector<SortAnalytics> analytics;

           
            bool orders[] = { true, false }; // Ascending, Descending
            bool criteria[] = { true, false }; // Sort by Average, Sort by Title

            for (bool sortByAverage : criteria) {
                for (bool ascending : orders) {
                    // Copia de datos para cada prueba
                    auto test_data_quick = *movie_averages;
                    auto test_data_merge = *movie_averages;

                    // Quick Sort
                    auto start_quick = std::chrono::high_resolution_clock::now();
                    quickSort(test_data_quick, 0, test_data_quick.size() - 1,
                        sortByAverage ? (ascending ? compareAverageAscending : compareAverageDescending)
                        : (ascending ? compareTitleAscending : compareTitleDescending));
                    auto end_quick = std::chrono::high_resolution_clock::now();
                    long long duration_quick = std::chrono::duration_cast<std::chrono::milliseconds>(end_quick - start_quick).count();

                    analytics.push_back({ "Quick Sort", sortByAverage ? "Average" : "Title", ascending ? "Ascending" : "Descending", duration_quick });

                    // Merge Sort
                    auto start_merge = std::chrono::high_resolution_clock::now();
                    mergeSort(test_data_merge, 0, test_data_merge.size() - 1,
                        sortByAverage ? (ascending ? compareAverageAscending : compareAverageDescending)
                        : (ascending ? compareTitleAscending : compareTitleDescending));
                    auto end_merge = std::chrono::high_resolution_clock::now();
                    long long duration_merge = std::chrono::duration_cast<std::chrono::milliseconds>(end_merge - start_merge).count();

                    analytics.push_back({ "Merge Sort", sortByAverage ? "Average" : "Title", ascending ? "Ascending" : "Descending", duration_merge });
                }
            }

         
            this->analyticsGridView->Rows->Clear();
            for (const SortAnalytics& result : analytics) {
                String^ algorithm = gcnew String(result.algorithm.c_str());
                String^ criteria = gcnew String(result.criteria.c_str());
                String^ order = gcnew String(result.order.c_str());
                String^ duration = result.duration.ToString();

                this->analyticsGridView->Rows->Add(algorithm, criteria, order, duration);
            }
        }


   
        void sortData()
        {
            if (movie_averages->empty())
                return;

            auto start_sort = std::chrono::high_resolution_clock::now();

            if (isQuickSortSelected)
            {
                if (isSortedByAverage)
                {
                    if (isAscending)
                    {
                        quickSort(*movie_averages, 0, movie_averages->size() - 1, compareAverageAscending);
                           
                    }
                    else
                    {
                        quickSort(*movie_averages, 0, movie_averages->size() - 1, compareAverageDescending);
                    }
                }
                else // Sort by title
                {
                    if (isAscending)
                    {
                        quickSort(*movie_averages, 0, movie_averages->size() - 1, compareTitleAscending);
                    }
                    else
                    {
                        quickSort(*movie_averages, 0, movie_averages->size() - 1, compareTitleDescending);
                    }
                }
            }
            else if (isMergeSortSelected)
            {
                if (isSortedByAverage)
                {
                    if (isAscending)
                    {
                        mergeSort(*movie_averages, 0, movie_averages->size() - 1, compareAverageAscending);
                    }
                    else
                    {
                        mergeSort(*movie_averages, 0, movie_averages->size() - 1, compareAverageDescending);
                    }
                }
                else // Sort by title
                {
                    if (isAscending)
                    {
                        mergeSort(*movie_averages, 0, movie_averages->size() - 1, compareTitleAscending);
                    }
                    else
                    {
                        mergeSort(*movie_averages, 0, movie_averages->size() - 1, compareTitleDescending);
                    }
                }
            }

            auto end_sort = std::chrono::high_resolution_clock::now();
            auto duration_sort = std::chrono::duration_cast<std::chrono::milliseconds>(end_sort - start_sort);

            String^ sortMethod = isQuickSortSelected ? "Quick Sort" : "Merge Sort";
            String^ order = isAscending ? "Ascending" : "Descending";
            String^ criteria = isSortedByAverage ? "Average" : "Title";

            String^ message = String::Format("Time for {0} {1} by {2}: {3} ms", sortMethod, order, criteria, duration_sort.count());

            MessageBox::Show(message);
        }

       
        int partition(std::vector<Movie_Average>& movies, int low, int high, bool (*comparator)(const Movie_Average&, const Movie_Average&)) {
            Movie_Average pivot = movies[high];
            int i = low - 1;

            for (int j = low; j < high; j++) {
                if (comparator(movies[j], pivot)) {
                    i++;
                    std::swap(movies[i], movies[j]);
                }
            }
            std::swap(movies[i + 1], movies[high]);
            return i + 1;
        }

        void quickSort(std::vector<Movie_Average>& movies, int low, int high, bool (*comparator)(const Movie_Average&, const Movie_Average&)) {
            if (low < high) {
                int pi = partition(movies, low, high, comparator);
                quickSort(movies, low, pi - 1, comparator);
                quickSort(movies, pi + 1, high, comparator);
            }
        }

        // Merge Sort functions with comparator
        void merge(std::vector<Movie_Average>& movies, int left, int mid, int right, bool (*comparator)(const Movie_Average&, const Movie_Average&)) {
            int n1 = mid - left + 1;
            int n2 = right - mid;

            std::vector<Movie_Average> L(n1);
            std::vector<Movie_Average> R(n2);

            for (int i = 0; i < n1; ++i)
                L[i] = movies[left + i];
            for (int j = 0; j < n2; ++j)
                R[j] = movies[mid + 1 + j];

            int i = 0, j = 0, k = left;

            while (i < n1 && j < n2) {
                if (comparator(L[i], R[j])) {
                    movies[k] = L[i];
                    i++;
                }
                else {
                    movies[k] = R[j];
                    j++;
                }
                k++;
            }

            while (i < n1) {
                movies[k] = L[i];
                i++;
                k++;
            }

            while (j < n2) {
                movies[k] = R[j];
                j++;
                k++;
            }
        }

        void mergeSort(std::vector<Movie_Average>& movies, int left, int right, bool (*comparator)(const Movie_Average&, const Movie_Average&)) {
            if (left < right) {
                int mid = left + (right - left) / 2;

                mergeSort(movies, left, mid, comparator);
                mergeSort(movies, mid + 1, right, comparator);

                merge(movies, left, mid, right, comparator);
            }
        }
    };

    // Comparator functions
    bool compareAverageAscending(const Movie_Average& a, const Movie_Average& b) {
        return a.average < b.average;
    }

    bool compareAverageDescending(const Movie_Average& a, const Movie_Average& b) {
        return a.average > b.average;
    }

    bool compareTitleAscending(const Movie_Average& a, const Movie_Average& b) {
        return a.title < b.title;
    }

    bool compareTitleDescending(const Movie_Average& a, const Movie_Average& b) {
        return a.title > b.title;
    }

}
