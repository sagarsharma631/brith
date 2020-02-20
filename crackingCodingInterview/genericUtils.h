#pragma once

template<typename T>
struct node {
	T data;
	struct node<T> *left;
	struct node<T> *right;
};

struct nodeInt {
	int data;
	struct nodeInt *left;
	struct nodeInt *right;
};

enum VIEWTYPE {
	VIEWTYPE_LEFT = 0,
	VIEWTYPE_RIGHT,
	VIEWTYPE_BOTTOM,
	VIEWTYPE_MAX,
};
