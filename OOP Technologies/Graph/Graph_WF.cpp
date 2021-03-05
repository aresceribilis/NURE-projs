#include "Graph_WF.h"/*
#include "Graph.h"*/
#include <Windows.h>
#include <iostream>
using namespace Graph;

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Graph_WF);

	return 0;
}