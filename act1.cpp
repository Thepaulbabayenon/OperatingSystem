//Paul Babayen-on BSCS4A
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// FCFS Disk Scheduling Algorithm
void fcfs(std::vector<int> requests, int head) {
    int totalSeekTime = 0;
    std::cout << "\nfcfs disk scheduling:\n";
    std::cout << "order of servicing requests: " << head;

    for (int request : requests) {
        totalSeekTime += std::abs(request - head);
        head = request;
        std::cout << " -> " << head;
    }

    std::cout << "\ntotal seek time: " << totalSeekTime << " cylinders\n";
}

// SSTF Disk Scheduling Algorithm
void sstf(std::vector<int> requests, int head) {
    int totalSeekTime = 0;
    std::cout << "\nsstf disk scheduling:\n";
    std::cout << "order of servicing requests: " << head;

    while (!requests.empty()) {
        // Find the closest request to the current head position
        auto closest = std::min_element(requests.begin(), requests.end(),
            [head](int a, int b) { return std::abs(a - head) < std::abs(b - head); });
        totalSeekTime += std::abs(*closest - head);
        head = *closest;
        std::cout << " -> " << head;
        requests.erase(closest);
    }

    std::cout << "\nTotal Seek Time: " << totalSeekTime << " cylinders\n";
}

int main() {
    int head, n;

    // Input: Initial head position
    std::cout << "enter initial head position: ";
    std::cin >> head;

    // Input: Number of disk requests
    std::cout << "enter the number of disk requests: ";
    std::cin >> n;

    // Input: Disk requests
    std::vector<int> requests(n);
    std::cout << "enter the disk requests:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> requests[i];
    }

    // Run the algorithms
    std::cout << "\ninitial head position: " << head << "\n";
    fcfs(requests, head);
    sstf(requests, head);

    return 0;
}
