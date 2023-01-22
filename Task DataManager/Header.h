#pragma once
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<unordered_map>

template<typename T>
class DataManager {
public:
	DataManager(const std::map<int, T>& myMap) : _myMap(myMap) {}
	void addMyMap(int key, const T& m) {
		if (_myMap.contains(key))
			std::cout << "ошибка, такой id существует\n";
		else
			_myMap.insert({ key, m });
	}
	void showMyMapAll() {
		for (auto i = _myMap.begin(); i != _myMap.end(); i++)
			std::cout << i->first << ' ' << i->second << "\n";
	}
	void Mod(int key, const T& mod) {
		auto it = _myMap.find(key);
		if (it != _myMap.end()) {
			it->second = mod;
			_keys.push_back(key);
		}
		else std::cout << "Id не еще не создан\n";
	}
	void Del(int key) {
		auto it = _myMap.find(key);
		if (it != _myMap.end()) {
			_myMap.erase(key);
		}
		else std::cout << "Id не еще не создан\n";
	}
	T Search(int key) {
		auto it = _myMap.find(key);
		if (it != _myMap.end()) {
			_keys.push_back(key);
			return it->second;
		}
		else
			return std::cout << "Id не еще не создан\n";
	}
	int mostSearchedKey() {
		std::unordered_map<int, int> keyAmount;
		for (size_t i = 0; i < _keys.size(); i++) {
			const auto& [it, isInserted] = keyAmount.insert({ _keys[i], 1 });
			if (!isInserted) {
				auto value = it->second;
				value++;
				keyAmount[_keys[i]] = value;
			}
		}
		
		std::pair<int, int> key_biggesValue = { 0,0 };
		for (std::unordered_map<int, int>::const_iterator it = keyAmount.begin(); it != keyAmount.end(); it++) {
			if (key_biggesValue.second < it->second) {
				key_biggesValue = std::make_pair(it->first, it->second);
			}
		}
		return key_biggesValue.first;
	}
private:
	std::map<int, T> _myMap;
	std::vector<int> _keys;
};
