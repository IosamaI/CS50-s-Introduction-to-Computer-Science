from django.urls import path
from . import views

urlpatterns = [
    path(
        "Search", views.movie_list_view, name="movie_list"
    ),  # Corrected the function name
    path("", views.allmovie, name="all_movies"),
]
