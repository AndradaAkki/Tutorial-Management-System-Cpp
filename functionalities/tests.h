/*#pragma once
#include <cassert>
#include <iostream>
#include "Service.h"
#include "Tutorial.h"
#include "Repo.h"
#include <sstream>
#include "UserService.h"
#include <vector>
"""class ServiceTests {
public:
    void run_all() {
        test_add();
        test_find_by_link();
        test_remove();
        test_update();
        test_get_tutorials();
        test_find_by_link_not_found();

        std::cout << "All Service tests passed!\n";
    }

private:
    void test_find_by_link_not_found() {
        Repo repo("");
        Service service(repo);

        service.add("C++ Basics", "John Doe", 10, 30, 100, "http://exists.com");

        Tutorial t = service.find_by_link("http://notfound.com");

        assert(t.get_link() == "");  // assuming default Tutorial has empty link
        std::cout << "test_find_by_link_not_found passed\n";
    }
    void test_add() {
        Repo repo;
        Service service(repo);

        service.add("C++ Basics", "John Doe", 10, 30, 100, "http://example.com");

        vector<Tutorial>& tutorials = service.getTutorials_nc();
		assert(tutorials[0].getString() == "C++ Basics John Doe 10:30 100 http://example.com");
        assert(tutorials.size() == 1);
        assert(tutorials[0].get_title() == "C++ Basics");
        assert(tutorials[0].get_link() == "http://example.com");

        std::cout << "test_add passed\n";
    }

    void test_find_by_link() {
        Repo repo;
        Service service(repo);

        service.add("C++ Basics", "John Doe", 10, 30, 100, "http://example.com");
        Tutorial t = service.find_by_link("http://example.com");

        assert(t.get_title() == "C++ Basics");
        assert(t.get_presenter() == "John Doe");

        std::cout << "test_find_by_link passed\n";
    }

    void test_remove() {
        Repo repo;
        Service service(repo);

        service.add("C++ Basics", "John Doe", 10, 30, 100, "http://example.com");
        service.remove("http://example.com");

        assert(service.getTutorials_nc().size() == 0);

        std::cout << "test_remove passed\n";
    }

    void test_update() {
        Repo repo;
        Service service(repo);

        service.add("C++ Basics", "John Doe", 10, 30, 100, "http://example.com");

        service.update("http://example.com", "Advanced C++", "Jane Smith", 20, 45, 250, "http://newlink.com");

        Tutorial t = service.find_by_link("http://newlink.com");

        assert(t.get_title() == "Advanced C++");
        assert(t.get_presenter() == "Jane Smith");
       
        assert(t.get_likes() == 250);

        std::cout << "test_update passed\n";
    }

    void test_get_tutorials() {
        Repo repo;
        Service service(repo);

        service.add("C++ Basics", "John Doe", 10, 30, 100, "http://example1.com");
        service.add("C++ Advanced", "Jane Doe", 20, 0, 150, "http://example2.com");

        vector<Tutorial>& tutorials = service.getTutorials_nc();

        assert(tutorials.size() == 2);
        assert(tutorials[0].get_link() == "http://example1.com");
        assert(tutorials[1].get_link() == "http://example2.com");

        std::cout << "test_get_tutorials passed\n";
    }
};
class RepoTests {
public:
    void run_all() {
        test_add();
        test_getTutorials();
        test_find();
        test_find_by_link();
        test_remove();
        test_update();

        std::cout << "All Repo tests passed!\n";
    }

private:
    void test_add() {
        Repo repo;
        Tutorial t{ "Title1", "Presenter1", {10, 30}, 100, "link1" };
        repo.add(t);

        auto& tutorials = repo.getTutorials_nc();
        assert(tutorials.size() == 1);
        assert(tutorials[0].get_title() == "Title1");

        std::cout << "test_add passed\n";
    }

    void test_getTutorials() {
        Repo repo;
        Tutorial t1{ "Title1", "Presenter1", {10, 30}, 100, "link1" };
        Tutorial t2{ "Title2", "Presenter2", {20, 45}, 150, "link2" };

        repo.add(t1);
        repo.add(t2);

        auto& tutorials = repo.getTutorials_nc();
        assert(tutorials.size() == 2);
        assert(tutorials[1].get_link() == "link2");

        std::cout << "test_getTutorials passed\n";
    }

    void test_find() {
        Repo repo;
        Tutorial t{ "Title1", "Presenter1", {10, 30}, 100, "link1" };
        repo.add(t);

        int index = repo.find(t);
        assert(index == 0);

        Tutorial notFound{ "Nope", "Nobody", {1, 1}, 1, "nope" };
        assert(repo.find(notFound) == -1);

        std::cout << "test_find passed\n";
    }

    void test_find_by_link() {
        Repo repo;
        Tutorial t{ "Title1", "Presenter1", {10, 30}, 100, "link1" };
        repo.add(t);

        assert(repo.find_by_link("link1") == 0);
        assert(repo.find_by_link("not_found") == -1);

        std::cout << "test_find_by_link passed\n";
    }

    void test_remove() {
        Repo repo;
        Tutorial t{ "Title1", "Presenter1", {10, 30}, 100, "link1" };
        repo.add(t);

        repo.remove(t);
        auto& tutorials = repo.getTutorials_nc();
        assert(tutorials.size() == 0);

        std::cout << "test_remove passed\n";
    }

    void test_update() {
        Repo repo;
        Tutorial t1{ "Title1", "Presenter1", {10, 30}, 100, "link1" };
        Tutorial t2{ "Updated Title", "Updated Presenter", {20, 50}, 200, "link1" };
        repo.add(t1);

        repo.update(t1, t2);
        auto& tutorials = repo.getTutorials_nc();
        
        
        assert(tutorials[0].get_title() == "Updated Title");
        assert(tutorials[0].get_likes() == 200);

        std::cout << "test_update passed\n";
    }
};
class UserServiceTests {
public:
    static void run_all_tests() {
        test_add_to_watch_later();
        test_delete_tutorial_liked();
        test_delete_tutorial_not_liked();
        std::cout << "All tests passed!\n";
    }

private:
    static void test_add_to_watch_later() {
        Repo repo;
        Tutorial t1("C++ Basics", "Alice", { 10, 30 }, 100, "link1");
        Tutorial t2("Advanced C++", "Bob", { 20, 0 }, 150, "link2");
        repo.add(t1);
        repo.add(t2);

        UserService service(repo);

        // Simulate display and manual watch later add
		service.getWatchLater_nc().push_back(t1);
        vector<Tutorial>& watchList = service.getWatchLater_nc();

        assert(watchList.size() == 1);
        assert(watchList[0].get_title() == "C++ Basics");
    }

    static void test_delete_tutorial_liked() {
        Repo repo;
        Tutorial t1("C++ Basics", "Alice", { 10, 30 }, 100, "link1");
        repo.add(t1);
        UserService service(repo);

		service.getWatchLater_nc().push_back(t1);

        // Simulate like
        std::cin.clear();
        std::istringstream input("1\n");
        std::cin.rdbuf(input.rdbuf());

        service.delete_tutorial_s("link1");

        assert(service.getWatchLater_nc().size() == 0);
        vector<Tutorial> all = repo.getTutorials();
        assert(all[0].get_likes() == 101);
    }

    static void test_delete_tutorial_not_liked() {
        Repo repo;
        Tutorial t1("C++ Basics", "Alice", { 10, 30 }, 100, "link1");
        repo.add(t1);
        UserService service(repo);

		service.getWatchLater_nc().push_back(t1);

        // Simulate no like
        std::cin.clear();
        std::istringstream input("0\n");
        std::cin.rdbuf(input.rdbuf());

        service.delete_tutorial_s("link1");

        assert(service.getWatchLater_nc().size() == 0);
        vector<Tutorial> all = repo.getTutorials();
        assert(all[0].get_likes() == 100);
    }
};*/