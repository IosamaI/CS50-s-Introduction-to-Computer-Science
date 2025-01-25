from django.shortcuts import render, get_object_or_404, redirect
from django.views.generic import ListView, DetailView
from .models import Movie, Review
from django.contrib.auth.decorators import login_required


def movie_list_view(request):
    return render(request, "movies_list.html")


def allmovie(request):
    return render(request, "allmovies.html")
