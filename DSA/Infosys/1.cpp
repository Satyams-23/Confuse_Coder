// Problem Explanation and Input Details
// In this problem, you're given a number of monsters, each with a certain power and a bonus. Your task is to determine the maximum number of monsters you can defeat given an initial amount of experience points. Here’s a breakdown of the input format:

// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int n; // number of monsters
//     int x; // initial experience points
//     cin >> n >> x;
//     vector<pair<int, int>> v; // vector to store power and bonus of each monster
//     for (int i = 0; i < n; i++)
//     {
//         int a, b;            // power and bonus of each monster
//         cin >> a >> b;       // input power and bonus of each monster
//         v.push_back({a, b}); //
//         cout << v[i].first << " " << v[i].second << endl;
//     }
//     sort(v.begin(), v.end()); // sort the vector based on power of monsters in ascending order

//     int count = 0; // variable to store the number of monsters defeated
//     for (int i = 0; i < n; i++)
//     {
//         if (v[i].first <= x) // if power of monster is less than or equal to initial experience points
//         {
//             x += v[i].second; // add bonus to experience points
//             count++;          // increment count
//         }
//     }

//     cout << "count" << count << endl; // output the number of monsters defeated

//     return 0;
// }

// Time Complexity Analysis
// T = O(nlogn) + O(n) = O(nlogn)

// Space Complexity Analysis
// S = O(n) + O(1) = O(n)

// In this problem, you have a certain number of heroes and villains, each with specified health points. The heroes and villains engage in a series of battles, and you need to determine the minimum number of villains to remove from the front of the list to ensure the heroes' victory.

// N = 4: There are 4 villains.
// M = 4: There are 4 heroes.
// H = 3: Each hero has a health of 3.
// Villain Healths = [3, 1, 3, 3]: The healths of the villains.

///////////////////////// Problem Set 2 /////////////////////////

// #include <iostream>
// #include <vector>
// using namespace std;

// int minimumVillainsToRemove(int n, int m, int h, const vector<int> &villains)
// {
//     int currentHeroes = m;
//     int currentHealth = h;

//     for (int i = 0; i < n; ++i)
//     {
//         if (currentHeroes == 0)
//         {
//             // No heroes left, return the number of villains remaining in front
//             return i;
//         }

//         cout << "Checking villain " << (i + 1) << " with health " << villains[i] << endl;

//         if (villains[i] < currentHealth)
//         {
//             // Villain is defeated
//             currentHealth -= villains[i];
//             cout << "Villain defeated. Hero's remaining health: " << currentHealth << endl;
//         }
//         else if (villains[i] == currentHealth)
//         {
//             // Both the hero and villain are defeated
//             currentHeroes--;   // Decrement the number of heroes
//             currentHealth = h; // Reset health for the next hero
//             cout << "Both defeated. Resetting hero's health. Remaining heroes: " << currentHeroes << endl;
//         }
//         else
//         {
//             // Hero can't defeat the villain
//             cout << "Hero cannot defeat this villain. Need to remove from front." << endl;
//             return i;
//         }
//     }

//     return i; // All villains can be defeated or removed from front
// }

// int main()
// {
//     int n, m, h;
//     cout << "Enter the number of villains: ";
//     cin >> n;
//     cout << "Enter the number of heroes: ";
//     cin >> m;
//     cout << "Enter the health of each hero: ";
//     cin >> h;

//     vector<int> villains(n);
//     cout << "Enter the healths of the villains: ";
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> villains[i];
//     }

//     int result = minimumVillainsToRemove(n, m, h, villains);
//     cout << "Minimum number of villains to remove: " << result << endl;

//     return 0;
// }

///////////////////////// Problem Set 3 /////////////////////////
