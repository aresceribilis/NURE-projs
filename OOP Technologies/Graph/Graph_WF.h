#pragma once

namespace Graph {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	#include "Graph.h"

	/// <summary>
	/// Сводка для Graph_WF
	/// </summary>
	public ref class Graph_WF : public System::Windows::Forms::Form
	{
	public:
		Graph_WF(void)
		{
			InitializeComponent();
			graph = new _Graph();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~Graph_WF()
		{
			if (components)
			{
				delete components;
			}
		}
	private: _Graph* graph;
	private: System::Windows::Forms::TextBox^ weight_matrix_textBox;
	private: System::Windows::Forms::TextBox^ source_textBox;
	private: System::Windows::Forms::TextBox^ target_textBox;
	private: System::Windows::Forms::TextBox^ weight_textBox;
	private: System::Windows::Forms::Label^ vertex_from;
	private: System::Windows::Forms::Label^ vertex_to;
	private: System::Windows::Forms::Label^ vertex_weight;
	private: System::Windows::Forms::Button^ add_edge;
	private: System::Windows::Forms::Button^ delete_edge;
	private: System::Windows::Forms::TextBox^ minimal_ways_textBox;
	private: System::Windows::Forms::Label^ minimal_ways_label;
	private: System::Windows::Forms::TextBox^ min_ostov_textBox;
	private: System::Windows::Forms::Label^ min_ostov_label;
	private: System::Windows::Forms::Label^ weight_matix_label;
	private: System::Windows::Forms::TextBox^ info_textBox;
	private: System::Windows::Forms::TextBox^ log_textBox;
	private: System::Windows::Forms::Label^ log_label;
	private: System::Windows::Forms::Label^ info_label;
	private: System::Windows::Forms::Button^ clear_graph_button;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->weight_matrix_textBox = (gcnew System::Windows::Forms::TextBox());
			this->source_textBox = (gcnew System::Windows::Forms::TextBox());
			this->target_textBox = (gcnew System::Windows::Forms::TextBox());
			this->weight_textBox = (gcnew System::Windows::Forms::TextBox());
			this->vertex_from = (gcnew System::Windows::Forms::Label());
			this->vertex_to = (gcnew System::Windows::Forms::Label());
			this->vertex_weight = (gcnew System::Windows::Forms::Label());
			this->add_edge = (gcnew System::Windows::Forms::Button());
			this->delete_edge = (gcnew System::Windows::Forms::Button());
			this->minimal_ways_textBox = (gcnew System::Windows::Forms::TextBox());
			this->minimal_ways_label = (gcnew System::Windows::Forms::Label());
			this->min_ostov_textBox = (gcnew System::Windows::Forms::TextBox());
			this->min_ostov_label = (gcnew System::Windows::Forms::Label());
			this->weight_matix_label = (gcnew System::Windows::Forms::Label());
			this->info_textBox = (gcnew System::Windows::Forms::TextBox());
			this->log_textBox = (gcnew System::Windows::Forms::TextBox());
			this->log_label = (gcnew System::Windows::Forms::Label());
			this->info_label = (gcnew System::Windows::Forms::Label());
			this->clear_graph_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// weight_matrix_textBox
			// 
			this->weight_matrix_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->weight_matrix_textBox->Location = System::Drawing::Point(218, 85);
			this->weight_matrix_textBox->Multiline = true;
			this->weight_matrix_textBox->Name = L"weight_matrix_textBox";
			this->weight_matrix_textBox->ReadOnly = true;
			this->weight_matrix_textBox->Size = System::Drawing::Size(300, 300);
			this->weight_matrix_textBox->TabIndex = 0;
			this->weight_matrix_textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// source_textBox
			// 
			this->source_textBox->Location = System::Drawing::Point(17, 28);
			this->source_textBox->Name = L"source_textBox";
			this->source_textBox->Size = System::Drawing::Size(38, 20);
			this->source_textBox->TabIndex = 1;
			this->source_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Graph_WF::deny_paste_KeyDown);
			this->source_textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Graph_WF::only_num_KeyPress);
			// 
			// target_textBox
			// 
			this->target_textBox->Location = System::Drawing::Point(61, 28);
			this->target_textBox->Name = L"target_textBox";
			this->target_textBox->Size = System::Drawing::Size(38, 20);
			this->target_textBox->TabIndex = 2;
			this->target_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Graph_WF::deny_paste_KeyDown);
			this->target_textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Graph_WF::only_num_KeyPress);
			// 
			// weight_textBox
			// 
			this->weight_textBox->Location = System::Drawing::Point(105, 28);
			this->weight_textBox->Name = L"weight_textBox";
			this->weight_textBox->Size = System::Drawing::Size(38, 20);
			this->weight_textBox->TabIndex = 3;
			this->weight_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Graph_WF::deny_paste_KeyDown);
			this->weight_textBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Graph_WF::only_num_KeyPress);
			// 
			// vertex_from
			// 
			this->vertex_from->AutoSize = true;
			this->vertex_from->Location = System::Drawing::Point(14, 12);
			this->vertex_from->Name = L"vertex_from";
			this->vertex_from->Size = System::Drawing::Size(44, 13);
			this->vertex_from->TabIndex = 0;
			this->vertex_from->Text = L"Начало";
			// 
			// vertex_to
			// 
			this->vertex_to->AutoSize = true;
			this->vertex_to->Location = System::Drawing::Point(61, 12);
			this->vertex_to->Name = L"vertex_to";
			this->vertex_to->Size = System::Drawing::Size(38, 13);
			this->vertex_to->TabIndex = 0;
			this->vertex_to->Text = L"Конец";
			// 
			// vertex_weight
			// 
			this->vertex_weight->AutoSize = true;
			this->vertex_weight->Location = System::Drawing::Point(111, 12);
			this->vertex_weight->Name = L"vertex_weight";
			this->vertex_weight->Size = System::Drawing::Size(26, 13);
			this->vertex_weight->TabIndex = 0;
			this->vertex_weight->Text = L"Вес";
			// 
			// add_edge
			// 
			this->add_edge->Location = System::Drawing::Point(149, 13);
			this->add_edge->Name = L"add_edge";
			this->add_edge->Size = System::Drawing::Size(80, 35);
			this->add_edge->TabIndex = 4;
			this->add_edge->Text = L"Добавить дугу";
			this->add_edge->UseVisualStyleBackColor = true;
			this->add_edge->Click += gcnew System::EventHandler(this, &Graph_WF::add_edge_Click);
			// 
			// delete_edge
			// 
			this->delete_edge->Location = System::Drawing::Point(235, 13);
			this->delete_edge->Name = L"delete_edge";
			this->delete_edge->Size = System::Drawing::Size(80, 35);
			this->delete_edge->TabIndex = 5;
			this->delete_edge->Text = L"Удалить дугу";
			this->delete_edge->UseVisualStyleBackColor = true;
			this->delete_edge->Click += gcnew System::EventHandler(this, &Graph_WF::delete_edge_Click);
			// 
			// minimal_ways_textBox
			// 
			this->minimal_ways_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->minimal_ways_textBox->Location = System::Drawing::Point(524, 85);
			this->minimal_ways_textBox->Multiline = true;
			this->minimal_ways_textBox->Name = L"minimal_ways_textBox";
			this->minimal_ways_textBox->ReadOnly = true;
			this->minimal_ways_textBox->Size = System::Drawing::Size(300, 300);
			this->minimal_ways_textBox->TabIndex = 6;
			this->minimal_ways_textBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// minimal_ways_label
			// 
			this->minimal_ways_label->AutoSize = true;
			this->minimal_ways_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->minimal_ways_label->Location = System::Drawing::Point(544, 58);
			this->minimal_ways_label->Name = L"minimal_ways_label";
			this->minimal_ways_label->Size = System::Drawing::Size(257, 24);
			this->minimal_ways_label->TabIndex = 7;
			this->minimal_ways_label->Text = L"Матрица кратчайших путей";
			// 
			// min_ostov_textBox
			// 
			this->min_ostov_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->min_ostov_textBox->Location = System::Drawing::Point(12, 188);
			this->min_ostov_textBox->Multiline = true;
			this->min_ostov_textBox->Name = L"min_ostov_textBox";
			this->min_ostov_textBox->ReadOnly = true;
			this->min_ostov_textBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->min_ostov_textBox->Size = System::Drawing::Size(200, 84);
			this->min_ostov_textBox->TabIndex = 8;
			// 
			// min_ostov_label
			// 
			this->min_ostov_label->AutoSize = true;
			this->min_ostov_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->min_ostov_label->Location = System::Drawing::Point(13, 161);
			this->min_ostov_label->Name = L"min_ostov_label";
			this->min_ostov_label->Size = System::Drawing::Size(196, 24);
			this->min_ostov_label->TabIndex = 10;
			this->min_ostov_label->Text = L"Минимальный остов";
			// 
			// weight_matix_label
			// 
			this->weight_matix_label->AutoSize = true;
			this->weight_matix_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->weight_matix_label->Location = System::Drawing::Point(268, 58);
			this->weight_matix_label->Name = L"weight_matix_label";
			this->weight_matix_label->Size = System::Drawing::Size(207, 24);
			this->weight_matix_label->TabIndex = 12;
			this->weight_matix_label->Text = L"Матрица весов графа";
			// 
			// info_textBox
			// 
			this->info_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->info_textBox->Location = System::Drawing::Point(12, 85);
			this->info_textBox->Multiline = true;
			this->info_textBox->Name = L"info_textBox";
			this->info_textBox->ReadOnly = true;
			this->info_textBox->Size = System::Drawing::Size(200, 70);
			this->info_textBox->TabIndex = 13;
			// 
			// log_textBox
			// 
			this->log_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->log_textBox->Location = System::Drawing::Point(9, 301);
			this->log_textBox->Multiline = true;
			this->log_textBox->Name = L"log_textBox";
			this->log_textBox->ReadOnly = true;
			this->log_textBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->log_textBox->Size = System::Drawing::Size(200, 84);
			this->log_textBox->TabIndex = 16;
			// 
			// log_label
			// 
			this->log_label->AutoSize = true;
			this->log_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->log_label->Location = System::Drawing::Point(83, 275);
			this->log_label->Name = L"log_label";
			this->log_label->Size = System::Drawing::Size(42, 24);
			this->log_label->TabIndex = 17;
			this->log_label->Text = L"Лог";
			// 
			// info_label
			// 
			this->info_label->AutoSize = true;
			this->info_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->info_label->Location = System::Drawing::Point(60, 58);
			this->info_label->Name = L"info_label";
			this->info_label->Size = System::Drawing::Size(107, 24);
			this->info_label->TabIndex = 18;
			this->info_label->Text = L"Инфо поле";
			// 
			// clear_graph_button
			// 
			this->clear_graph_button->Location = System::Drawing::Point(321, 13);
			this->clear_graph_button->Name = L"clear_graph_button";
			this->clear_graph_button->Size = System::Drawing::Size(80, 35);
			this->clear_graph_button->TabIndex = 19;
			this->clear_graph_button->Text = L"Очистить граф";
			this->clear_graph_button->UseVisualStyleBackColor = true;
			this->clear_graph_button->Click += gcnew System::EventHandler(this, &Graph_WF::clear_graph_button_Click);
			// 
			// Graph_WF
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(836, 392);
			this->Controls->Add(this->clear_graph_button);
			this->Controls->Add(this->info_label);
			this->Controls->Add(this->log_label);
			this->Controls->Add(this->log_textBox);
			this->Controls->Add(this->info_textBox);
			this->Controls->Add(this->weight_matix_label);
			this->Controls->Add(this->min_ostov_label);
			this->Controls->Add(this->min_ostov_textBox);
			this->Controls->Add(this->minimal_ways_label);
			this->Controls->Add(this->minimal_ways_textBox);
			this->Controls->Add(this->delete_edge);
			this->Controls->Add(this->add_edge);
			this->Controls->Add(this->vertex_weight);
			this->Controls->Add(this->vertex_to);
			this->Controls->Add(this->vertex_from);
			this->Controls->Add(this->weight_textBox);
			this->Controls->Add(this->target_textBox);
			this->Controls->Add(this->source_textBox);
			this->Controls->Add(this->weight_matrix_textBox);
			this->Name = L"Graph_WF";
			this->Text = L"Graph_WF";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	   // запрещает пользователю вводить что-либо, кроме цифр
	private: System::Void only_num_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08)
			e->Handled = true;
	}
	   // запрещает пользователю вставлять информацию через комбинацию клавиш Ctrl+V
private: System::Void deny_paste_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	((TextBox^)sender)->ContextMenu = nullptr;
	((TextBox^)sender)->ContextMenuStrip = nullptr;
}
	   //вспомогательная функция для событий add_edge_Click и delete_edge_Click. обновляет нек-рые информационные поля
private: void info_update() {
	String^ info, ^ weight_matrix, ^ minimal_ways, ^ minimal_ostov;

	info += "Кол-во вершин: " + graph->get_count_of_unique().ToString() + "\r\n";
	info += "Кол-во дуг: " + graph->get_count_of_edges().ToString() + "\r\n";
	int** weights = graph->get_weight_matrix();
	int count_of_unique = graph->get_count_of_unique();
	int* array_of_unique = graph->get_array_of_unique();
	int** distances = graph->get_minimal_ways();

	if (graph->get_connectivity_component_count() == 1) {
		int** min_ostov = graph->get_minimal_ostov();

		int min_ostov_value = 0;
		for (int i = 0; i < count_of_unique - 1; ++i) {
			minimal_ostov += (array_of_unique[min_ostov[i][0]]).ToString() + " -> " + (array_of_unique[min_ostov[i][1]]).ToString() + ", ";// << " = " << min_ostov[i][2];
			min_ostov_value += min_ostov[i][2];
		}
		minimal_ostov += "\r\nВес мин остова: " + min_ostov_value.ToString();
	}
	else {
		minimal_ostov = "Вес мин остова определить нельзя, ибо компонента связности не одна!";
	}

	weight_matrix += "      ";
	minimal_ways += "      ";
	for (int i = 0; i < count_of_unique; ++i) {
		weight_matrix += array_of_unique[i].ToString() + "    ";
		minimal_ways += array_of_unique[i].ToString() + "    ";
	}
	weight_matrix += "\r\n";
	minimal_ways += "\r\n";

	for (int i = 0; i < count_of_unique; ++i, weight_matrix += "\r\n", minimal_ways += "\r\n") {
		weight_matrix += array_of_unique[i].ToString() + "    ";
		minimal_ways += array_of_unique[i].ToString() + "    ";
		for (int j = 0; j < count_of_unique; ++j) {
			weight_matrix += weights[i][j].ToString() + "    ";
			distances[i][j] == 1000000 ?
				minimal_ways += "0    " :
				minimal_ways += distances[i][j].ToString() + "    ";
		}
	}
	info += "Кол-во компонент связности: " + graph->get_connectivity_component_count().ToString();
	info_textBox->Text = info;
	weight_matrix_textBox->Text = weight_matrix;
	minimal_ways_textBox->Text = minimal_ways;
	min_ostov_textBox->Text = minimal_ostov;
}
	   // для добавления дуги в граф
private: System::Void add_edge_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ cpy, ^log;
	if (!source_textBox->Text->Length || !target_textBox->Text->Length || !weight_textBox->Text->Length) {
		cpy = log_textBox->Text;
		log_textBox->Text = "";
		log_textBox->Text += "Отказ! (пустые поля)\r\n";
		log_textBox->Text += cpy;
	}
	else if (source_textBox->Text == target_textBox->Text) {
		cpy = log_textBox->Text;
		log_textBox->Text = "";
		log_textBox->Text += "Отказ! (петля)\r\n";
		log_textBox->Text += cpy;
	}
	else if (weight_textBox->Text == "0") {
		cpy = log_textBox->Text;
		log_textBox->Text = "";
		log_textBox->Text += "Отказ! (нулевой вес)\r\n";
		log_textBox->Text += cpy;
	}
	else {
		String^ id_from = source_textBox->Text;
		String^ id_to = target_textBox->Text;
		String^ _weight = weight_textBox->Text;

		int source, target, weight;
		source = source.Parse(id_from);
		target = target.Parse(id_to);
		weight = weight.Parse(_weight);

		int res = graph->Add(source, target, weight);
		log = "Дуга " + id_from + " - > " + id_to + " с весом " + _weight;
		switch (res) {
		case 0:
			log += " перезаписана!\r\n"; break;
		case 1:
			log += " не перезаписана!\r\n"; break;
		case 2:
			log += " добавлена!\r\n"; break;
		}
		info_update();

		cpy = log_textBox->Text;
		log_textBox->Text = "";
		log_textBox->Text += log;
		log_textBox->Text += cpy;
	}
}
	   // для удаления дуги из графа
private: System::Void delete_edge_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ cpy, ^ log;
	if (!source_textBox->Text->Length || !target_textBox->Text->Length || !weight_textBox->Text->Length) {
		cpy = log_textBox->Text;
		log_textBox->Text = "";
		log_textBox->Text += "Отказ! (пустые поля)\r\n";
		log_textBox->Text += cpy;
	}
	else if (source_textBox->Text == target_textBox->Text) {
		cpy = log_textBox->Text;
		log_textBox->Text = "";
		log_textBox->Text += "Отказ! (петля)\r\n";
		log_textBox->Text += cpy;
	}
	else {
		String^ id_from = source_textBox->Text;
		String^ id_to = target_textBox->Text;

		int source, target;
		source = source.Parse(id_from);
		target = target.Parse(id_to);

		int res = graph->Pop(source, target);
		log = "Дуга " + id_from + " - > " + id_to;
		switch (res) {
		case 0:
			log += " не удалёна, ведь граф уже пуст!\r\n"; break;
		case 1:
			log += " удалёна!\r\n"; break;
		case 2:
			log += " не найдена!\r\n"; break;
		}
		info_update();

		cpy = log_textBox->Text;
		log_textBox->Text = "";
		log_textBox->Text += log;
		log_textBox->Text += cpy;
	}
}
	   // для очистки графа от дуг
private: System::Void clear_graph_button_Click(System::Object^ sender, System::EventArgs^ e) {
	graph->Clear_graph();
	info_textBox->Text = "";
	log_textBox->Text = "";
	weight_matrix_textBox->Text = "";
	minimal_ways_textBox->Text = "";
	min_ostov_textBox->Text = "";
	source_textBox->Text = "";
	target_textBox->Text = "";
	weight_textBox->Text = "";
}
};
}