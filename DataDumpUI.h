#pragma once

//#include "FileManager.h"
#include "strings.h"
#include "types.h"



namespace DataDump {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DataDumpUI
	/// </summary>
	public ref class DataDumpUI : public System::Windows::Forms::Form
	{
	public:
		DataDumpUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  numOffsetAmount;

	public:

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>

		System::String^ filename;

		~DataDumpUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  openToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  copyToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  pasteToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  rdoBin;

	private: System::Windows::Forms::RadioButton^  rdoHex;

	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::RadioButton^  rdo64;

	private: System::Windows::Forms::RadioButton^  rdo32;


	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::RadioButton^  rdoLE;

	private: System::Windows::Forms::RadioButton^  rdoBE;


	private: System::Windows::Forms::Label^  label1;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  cmb_epoch;
	private: System::Windows::Forms::RichTextBox^  txtOffset;
	private: System::Windows::Forms::RichTextBox^  txtASCII;


	private: System::Windows::Forms::RichTextBox^  txtData;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  btnStartInterpret;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(DataDumpUI::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copyToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pasteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rdoBin = (gcnew System::Windows::Forms::RadioButton());
			this->rdoHex = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->rdo64 = (gcnew System::Windows::Forms::RadioButton());
			this->rdo32 = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->rdoLE = (gcnew System::Windows::Forms::RadioButton());
			this->rdoBE = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cmb_epoch = (gcnew System::Windows::Forms::ComboBox());
			this->txtOffset = (gcnew System::Windows::Forms::RichTextBox());
			this->txtASCII = (gcnew System::Windows::Forms::RichTextBox());
			this->txtData = (gcnew System::Windows::Forms::RichTextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnStartInterpret = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numOffsetAmount = (gcnew System::Windows::Forms::NumericUpDown());
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numOffsetAmount))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->editToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(843, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->toolStripSeparator1, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &DataDumpUI::openToolStripMenuItem_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(143, 6);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(146, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &DataDumpUI::exitToolStripMenuItem_Click);
			// 
			// editToolStripMenuItem
			// 
			this->editToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->copyToolStripMenuItem,
					this->pasteToolStripMenuItem
			});
			this->editToolStripMenuItem->Name = L"editToolStripMenuItem";
			this->editToolStripMenuItem->Size = System::Drawing::Size(39, 20);
			this->editToolStripMenuItem->Text = L"Edit";
			// 
			// copyToolStripMenuItem
			// 
			this->copyToolStripMenuItem->Name = L"copyToolStripMenuItem";
			this->copyToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C));
			this->copyToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->copyToolStripMenuItem->Text = L"Copy";
			// 
			// pasteToolStripMenuItem
			// 
			this->pasteToolStripMenuItem->Enabled = false;
			this->pasteToolStripMenuItem->Name = L"pasteToolStripMenuItem";
			this->pasteToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->pasteToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->pasteToolStripMenuItem->Text = L"Paste";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->aboutToolStripMenuItem });
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->ShortcutKeys = System::Windows::Forms::Keys::F1;
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(126, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rdoBin);
			this->groupBox1->Controls->Add(this->rdoHex);
			this->groupBox1->Location = System::Drawing::Point(12, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(108, 73);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Display";
			// 
			// rdoBin
			// 
			this->rdoBin->AutoSize = true;
			this->rdoBin->Location = System::Drawing::Point(7, 44);
			this->rdoBin->Name = L"rdoBin";
			this->rdoBin->Size = System::Drawing::Size(54, 17);
			this->rdoBin->TabIndex = 1;
			this->rdoBin->Text = L"Binary";
			this->rdoBin->UseVisualStyleBackColor = true;
			// 
			// rdoHex
			// 
			this->rdoHex->AutoSize = true;
			this->rdoHex->Checked = true;
			this->rdoHex->Location = System::Drawing::Point(7, 20);
			this->rdoHex->Name = L"rdoHex";
			this->rdoHex->Size = System::Drawing::Size(86, 17);
			this->rdoHex->TabIndex = 0;
			this->rdoHex->TabStop = true;
			this->rdoHex->Text = L"Hexadecimal";
			this->rdoHex->UseVisualStyleBackColor = true;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->rdo64);
			this->groupBox2->Controls->Add(this->rdo32);
			this->groupBox2->Location = System::Drawing::Point(126, 27);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(79, 73);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Bit Length";
			// 
			// rdo64
			// 
			this->rdo64->AutoSize = true;
			this->rdo64->Location = System::Drawing::Point(7, 44);
			this->rdo64->Name = L"rdo64";
			this->rdo64->Size = System::Drawing::Size(52, 17);
			this->rdo64->TabIndex = 1;
			this->rdo64->Text = L"64-Bit";
			this->rdo64->UseVisualStyleBackColor = true;
			// 
			// rdo32
			// 
			this->rdo32->AutoSize = true;
			this->rdo32->Checked = true;
			this->rdo32->Location = System::Drawing::Point(7, 20);
			this->rdo32->Name = L"rdo32";
			this->rdo32->Size = System::Drawing::Size(52, 17);
			this->rdo32->TabIndex = 0;
			this->rdo32->TabStop = true;
			this->rdo32->Text = L"32-Bit";
			this->rdo32->UseVisualStyleBackColor = true;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->rdoLE);
			this->groupBox3->Controls->Add(this->rdoBE);
			this->groupBox3->Location = System::Drawing::Point(211, 27);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(97, 73);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Endianness";
			// 
			// rdoLE
			// 
			this->rdoLE->AutoSize = true;
			this->rdoLE->Location = System::Drawing::Point(7, 44);
			this->rdoLE->Name = L"rdoLE";
			this->rdoLE->Size = System::Drawing::Size(83, 17);
			this->rdoLE->TabIndex = 1;
			this->rdoLE->Text = L"Little-Endian";
			this->rdoLE->UseVisualStyleBackColor = true;
			// 
			// rdoBE
			// 
			this->rdoBE->AutoSize = true;
			this->rdoBE->Checked = true;
			this->rdoBE->Location = System::Drawing::Point(7, 20);
			this->rdoBE->Name = L"rdoBE";
			this->rdoBE->Size = System::Drawing::Size(76, 17);
			this->rdoBE->TabIndex = 0;
			this->rdoBE->TabStop = true;
			this->rdoBE->Text = L"Big-Endian";
			this->rdoBE->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 108);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Offset";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(537, 108);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"ASCII";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(314, 27);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 13);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Epoch";
			// 
			// cmb_epoch
			// 
			this->cmb_epoch->FormattingEnabled = true;
			this->cmb_epoch->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"January 1, 1970", L"January 1, 2001" });
			this->cmb_epoch->Location = System::Drawing::Point(317, 43);
			this->cmb_epoch->Name = L"cmb_epoch";
			this->cmb_epoch->Size = System::Drawing::Size(121, 21);
			this->cmb_epoch->TabIndex = 10;
			this->cmb_epoch->Enter += gcnew System::EventHandler(this, &DataDumpUI::cmb_epoch_Enter);
			this->cmb_epoch->Leave += gcnew System::EventHandler(this, &DataDumpUI::cmb_epoch_Leave);
			// 
			// txtOffset
			// 
			this->txtOffset->BackColor = System::Drawing::SystemColors::Window;
			this->txtOffset->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtOffset->Location = System::Drawing::Point(12, 124);
			this->txtOffset->Name = L"txtOffset";
			this->txtOffset->ReadOnly = true;
			this->txtOffset->Size = System::Drawing::Size(108, 312);
			this->txtOffset->TabIndex = 11;
			this->txtOffset->Text = L"";
			// 
			// txtASCII
			// 
			this->txtASCII->BackColor = System::Drawing::SystemColors::Window;
			this->txtASCII->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtASCII->Location = System::Drawing::Point(540, 124);
			this->txtASCII->Name = L"txtASCII";
			this->txtASCII->ReadOnly = true;
			this->txtASCII->Size = System::Drawing::Size(291, 312);
			this->txtASCII->TabIndex = 12;
			this->txtASCII->Text = L"";
			// 
			// txtData
			// 
			this->txtData->BackColor = System::Drawing::SystemColors::Window;
			this->txtData->Font = (gcnew System::Drawing::Font(L"Consolas", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtData->Location = System::Drawing::Point(127, 124);
			this->txtData->Name = L"txtData";
			this->txtData->ReadOnly = true;
			this->txtData->Size = System::Drawing::Size(407, 312);
			this->txtData->TabIndex = 13;
			this->txtData->Text = L"";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(124, 108);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(30, 13);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Data";
			// 
			// btnStartInterpret
			// 
			this->btnStartInterpret->Location = System::Drawing::Point(317, 77);
			this->btnStartInterpret->Name = L"btnStartInterpret";
			this->btnStartInterpret->Size = System::Drawing::Size(121, 23);
			this->btnStartInterpret->TabIndex = 15;
			this->btnStartInterpret->Text = L"Start Interpreter";
			this->btnStartInterpret->UseVisualStyleBackColor = true;
			this->btnStartInterpret->Click += gcnew System::EventHandler(this, &DataDumpUI::btnStartInterpret_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(441, 27);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(74, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Offset Amount";
			// 
			// numOffsetAmount
			// 
			this->numOffsetAmount->Location = System::Drawing::Point(444, 44);
			this->numOffsetAmount->Name = L"numOffsetAmount";
			this->numOffsetAmount->Size = System::Drawing::Size(120, 20);
			this->numOffsetAmount->TabIndex = 18;
			this->numOffsetAmount->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 16, 0, 0, 0 });
			// 
			// DataDumpUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(843, 448);
			this->Controls->Add(this->numOffsetAmount);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->btnStartInterpret);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtData);
			this->Controls->Add(this->txtASCII);
			this->Controls->Add(this->txtOffset);
			this->Controls->Add(this->cmb_epoch);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"DataDumpUI";
			this->Text = L"DataDump";
			this->Load += gcnew System::EventHandler(this, &DataDumpUI::DataDumpUI_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numOffsetAmount))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DataDumpUI_Load(System::Object^  sender, System::EventArgs^  e) 
	{
		this->cmb_epoch->SelectedItem = this->cmb_epoch->Items[0];

#define PLACEHOLDER_TEXT ":PLACEHOLDER:\n0x00000000\n1234567890\nABCDEFGHIJKLMNOPQRSTUVWXYZ"
#ifdef PLACEHOLDER_TEXT
		this->txtASCII->Text = PLACEHOLDER_TEXT;
		this->txtData->Text = PLACEHOLDER_TEXT;
		this->txtOffset->Text = PLACEHOLDER_TEXT;
#undef PLACEHOLDER_TEXT
#endif
	}

private: System::Void openToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	OFDialog^ dialog = gcnew OFDialog();

	if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
		this->filename = dialog->FileName;
	}
	else {
		this->filename = "";
	}

	// MessageBox::Show(this->filename); // Verify the filename is being stored correctly
}
private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	Application::Exit();
}
private: System::Void btnStartInterpret_Click(System::Object^  sender, System::EventArgs^  e) {
	//MessageBox::Show("Started Interpreting");
	
}

private: System::Void cmb_epoch_Enter(System::Object^  sender, System::EventArgs^  e) {
	//MessageBox::Show("Entered!");
	this->pasteToolStripMenuItem->Enabled = true;
}
private: System::Void cmb_epoch_Leave(System::Object^  sender, System::EventArgs^  e) {
	//MessageBox::Show("Exited!");
	this->pasteToolStripMenuItem->Enabled = false;
}
};
}
