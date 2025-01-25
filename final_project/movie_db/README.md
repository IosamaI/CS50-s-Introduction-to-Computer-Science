# Movie Database Platform

#### Video Demo: <URL (https://youtu.be/6Iry5FTBOCE)>

#### Description:
The Movie Database Platform is a web-based application that allows users to search for movies, view movie details (including title, genre, director, actors, IMDb rating, and plot), and explore a collection of top movies. The application retrieves movie data from the OMDb API using JavaScript for the frontend and Django (Python) for the backend. It provides a simple and user-friendly interface to interact with movie data.

### Key Features:
- **Search for Movies**: Users can search for any movie by entering its title, and the platform will fetch movie details from the OMDb API.
- **Display Movie Information**: After a search, the platform shows detailed information for the movie, including its genre, director, actors, plot, IMDb rating, and poster image.
- **Top 20 Movies**: The platform also showcases a pre-defined list of the top 20 movies, fetching data from the OMDb API to display movie details for each one.

### Technologies Used:
- **Frontend**: HTML, CSS, JavaScript
  - **OMDb API**: Used for fetching movie data.
- **Backend**: Django (Python), SQLite (Database)
  - Django handles the backend logic, URL routing, and views.
- **Database**: SQLite (for any potential expansion in the future, such as storing user reviews, etc.)

### File Breakdown:
1. **`urls.py`**: Contains URL routing logic for the project. This is where the movie list and all movies' views are mapped.
   - The URL patterns are defined for two main views: the movie list view and the all movies view.
   
2. **`views.py`**: Contains the logic for rendering the views in response to user requests.
   - **`movie_list_view`**: Renders the movie list page, which displays the top 20 movies from the OMDb API.
   - **`allmovie`**: Displays the all movies page, which can be expanded in the future to show all movie data or any additional content.

3. **`movies_list.html`**: This is the template where the top 20 movies are displayed. JavaScript fetches movie data from the OMDb API for each movie title and dynamically generates HTML content.
   - The movie details (title, genre, director, actors, etc.) are displayed using `movie-card` styles.
   
4. **`allmovies.html`**: This is the template for the all-movies page. It can be extended to display more features, such as all movie reviews or additional content from the database.

5. **JavaScript (Frontend Logic)**: The JavaScript code interacts with the OMDb API to fetch and display movie details. The `fetch()` function retrieves movie data, and dynamic content is inserted into the HTML based on the data fetched.

6. **Styling**: Basic CSS is used to make the movie cards look visually appealing, with responsive layouts for the movie list and individual movie details.

### Design Choices:
- **Frontend/Backend Separation**: The frontend handles fetching data from the OMDb API, while Django serves as the backend. This separation of concerns helps keep the logic for rendering movie data and user interface distinct and organized.
- **Fetching Movies on Load**: The decision to fetch the top 20 movies on page load ensures that users immediately have access to popular movies. It eliminates the need for manual data entry or further API calls when browsing the movie list.
- **Error Handling**: If the OMDb API does not return any movie data (e.g., movie not found), fallback data is provided. This ensures that the user experience is not disrupted and that something is displayed even when a movie search fails.

### Potential Improvements:
- **User Reviews**: Adding functionality for users to leave reviews for movies. This could involve creating a review model in Django and allowing users to submit their reviews.
- **Pagination**: For a large list of movies or top-rated movies, implementing pagination could improve performance and user experience.
- **Authentication**: Adding user authentication (using Django’s built-in authentication system) would allow users to log in, track their favorite movies, and leave reviews.

### How to Run the Project:
1. Clone the repository to your local machine:
   ```bash
   git clone <repository-url>
