#include "common.h"


std::vector<std::string> split(const std::string &str, char d)
{
        std::vector<std::string> r;

        std::string::size_type start = 0;
        std::string::size_type stop = str.find_first_of(d);
        while(stop != std::string::npos)
        {
            r.push_back(str.substr(start, stop - start));

            start = stop + 1;
            stop = str.find_first_of(d, start);
        }

        r.push_back(str.substr(start));

        return r;
}


int main() {
    try {
        std::vector<std::vector<std::string>> ip_pool;
        std::vector<unsigned long long> ull_ip_pool;

        for (std::string line; std::getline(std::cin, line);)
        {
            if (line.empty())
                break;
            std::vector<std::string> tmp_v = split(line, '\t');
            ip_pool.push_back(split(tmp_v.at(0), '.'));
        }

        for (auto upper = ip_pool.begin(); upper != ip_pool.end(); ++upper) {
            ull_ip_pool.push_back(getUlongValueOfIpv4(*upper));
        }

        for (auto upper_it = ull_ip_pool.begin(); upper_it != ull_ip_pool.end(); upper_it++) {
            for (auto inner_it = ull_ip_pool.begin(); inner_it != ull_ip_pool.end(); inner_it++) {
                if (*inner_it < *upper_it) {
                    unsigned long long tmp = *inner_it;

                    auto _tmp = ip_pool.at(std::distance(ull_ip_pool.begin(), inner_it));
                    auto& _inner = ip_pool.at(std::distance(ull_ip_pool.begin(), inner_it));
                    auto& _upper = ip_pool.at(std::distance(ull_ip_pool.begin(), upper_it));
                
                    _inner = std::vector<std::string>(_upper);
                    _upper = _tmp;

                    *inner_it = *upper_it;
                    *upper_it = tmp;
                }
            }
        }

        for (auto elem : ip_pool) {
            std::string result;
            for (auto sub_elem : elem) {
                result += sub_elem + '.';
            }
            result.erase(result.size() - 1, 1);
            std::cout << result << std::endl;
        }

         for (auto& elem : ip_pool) {
            if (elem[0] == "1") {
                std::string result;
                for (auto it = elem.begin(); it != elem.end(); it++) {
                    result += *it + '.';
                }
                result.erase(result.size() - 1, 1);
                std::cout << result << std::endl;
            }
        }

        for (auto& elem : ip_pool) {
            if (elem[0] == "46" && elem[1] == "70") {
                std::string result;
                for (auto it = elem.begin(); it != elem.end(); it++) {
                    result += *it + '.';
                }
                result.erase(result.size() - 1, 1);
                std::cout << result << std::endl;
            }
        }
       
        for (auto elem : ip_pool) {
            if (std::find(elem.begin(), elem.end(), std::string("46")) != elem.end() ) {
                std::string result;
                for (auto it = elem.begin(); it != elem.end(); it++) {
                    result += *it + '.';
                }
                result.erase(result.size() - 1, 1);
                std::cout << result << std::endl;
            }
        }
    }

    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        exit(EXIT_FAILURE);
    }
}