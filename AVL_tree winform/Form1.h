#pragma once
#include"file.h"
#include"Avl.h"
namespace AVL_treewinform {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Panel^  panel1;
	public: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button3;
	public: 
	protected: 


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(19, 10);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(123, 33);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Build Up tree";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(12, 63);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1388, 769);
			this->panel1->TabIndex = 1;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panel1_Paint);
			this->panel1->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::panel1_Scroll);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(10000, 10000);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::pictureBox1_Paint);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(12, 2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(159, 55);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Location = System::Drawing::Point(177, 2);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(324, 55);
			this->groupBox2->TabIndex = 3;
			this->groupBox2->TabStop = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(109, 19);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(209, 20);
			this->textBox1->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(3, 16);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Insert";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->textBox2);
			this->groupBox3->Controls->Add(this->button3);
			this->groupBox3->Location = System::Drawing::Point(525, 2);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(313, 55);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(84, 18);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(211, 20);
			this->textBox2->TabIndex = 1;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(3, 16);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Delete";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->ClientSize = System::Drawing::Size(1136, 717);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &Form1::Form1_Scroll);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		System::Drawing::Graphics ^g;
		System::Drawing::Pen ^BluePen;
		System::Drawing::Pen ^BlackPen;
		System::Drawing::SolidBrush^ BlackBrush;
		System::Drawing::Brush^ WhiteBrush;
		System::Drawing::Brush^ RedBrush;
		static System::Drawing::Font^ ArialFont;
		Avl *T;
		String^ convert(char *str1)
		{
			String ^str;
			for(int i=0 ; i<11 ; i++)
			{
				str+=Convert::ToChar(str1[i]);
			}
			str+="\r\n";
			return str;
		}
		//////-------------------------------------
		void print_inorder(Avl *T)
		{
			if(T!=NULL)
			{
				print_inorder(T->L);
				print_inorder(T->R);
			}
		}
		//-----------------------------------------------
		char* convert1(String ^str)
		{
			char *str1=new char[12];
			for(int i=0 ; i<11 ; i++)
			{
				str1[i]=str[i];
			}
			str1[11]='\0';
			return str1;
		}
		//-----------------------------------------------
		void Draw_tree(Avl* T , int x , int y ,int newx,int newy , int L ,int c)
		 {

			if (T!=NULL)
			{
				y+=40;
				if (T->R!=NULL)
				{	  
					newx=x+(L/2);
					newy=y+60;
					g->DrawLine(BluePen,x,y,newx,newy);
				}
				if (T->L!=NULL)
				{
					newx=x-(L/2);
					newy=y+60;
					g->DrawLine(BluePen,x,y,newx,newy);
				}
				if(c==0)
				{
					g->FillEllipse(RedBrush,(x-10),(y-40),50,20);
					//g->FillRectangle(RedBrush,(x-10),(y-40),50,20)
					g->DrawEllipse(BlackPen,(x-10),(y-40),50,20);
					g->DrawString("Root",ArialFont,BlackBrush,(x-3),(y-40));
				}
				g->FillRectangle(WhiteBrush,(x-40),(y-10),100,20);
				g->DrawRectangle(BlackPen,(x-40),(y-10),100,20);
				g->DrawString(convert(T->num),ArialFont,BlackBrush,(x-40),(y-10));
				newx=x;
				newy=y;
				c++;
				Draw_tree(T->L,x-(L/2),(y+20),newx,newy,L/2,c);
				Draw_tree(T->R,x+(L/2),(y+20),newx,newy,L/2,c);

			}
		 }// end fnction

		//-----------------------------------------------
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 this->Refresh();
				 g=pictureBox1->CreateGraphics();
				 BluePen=gcnew Pen(Color::Blue);
				 BluePen->DashCap= DashCap::Round;
				 BlackPen=gcnew Pen(Color::Black);
				 BlackBrush=gcnew SolidBrush(Color::Black);
				 WhiteBrush=gcnew SolidBrush(Color::White);
				 RedBrush=gcnew SolidBrush(Color::Red);
				 ArialFont=gcnew Drawing::Font("Arial",11);
				 Point P1 ;
				 Point P2 ;
				 P1.X=5075;
				 P1.Y=30;
				 P2.X=5075;
				 P2.Y=30;
				 int L=5000;
				 int c=0;
				 T=new Avl;
				 T=buildup_tree();
				 Draw_tree(T,P1.X,P2.Y,P2.X,P2.Y,L,c);
			 }
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void Form1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
			 }
private: System::Void panel1_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
					 Point P1 ;
					 Point P2 ;
					 P1.X=5075;
					 P1.Y=30;
					 P2.X=5075;
					 P2.Y=30;
					 int L=5000;
					 pictureBox1->Refresh();
					 int c=0;
					 Draw_tree(T,P1.X,P2.Y,P2.X,P2.Y,L,c);
		 }
private: System::Void pictureBox1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			  //Draw_tree(T);
			  
		 }
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 //Draw_tree(T);
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 bool h=false;
			 Avl element;
			 String ^str;
			 str=textBox1->Text;
			 char *str1;
			 str1=convert1(str);
			 strcpy(element.num,str1);
			 T=Insert1(T,element,h);
			 Point P1 ;
			 Point P2 ;
			 P1.X=5075;
			 P1.Y=30;
			 P2.X=5075;
			 P2.Y=30;
			 int L=5000;
			 pictureBox1->Refresh();
			 int c=0;
			 Draw_tree(T,P1.X,P2.Y,P2.X,P2.Y,L,c);
		 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			 bool h=false;
			 Avl element;
			 String ^str;
			 str=textBox2->Text;
			 strcpy(element.num,convert1(str));
			 T=Delete_element1(T,element,h);
			 Point P1 ;
			 Point P2 ;
			 P1.X=5075;
			 P1.Y=30;
			 P2.X=5075;
			 P2.Y=30;
			 int L=5000;
			 pictureBox1->Refresh();
			 int c=0;
			 Draw_tree(T,P1.X,P2.Y,P2.X,P2.Y,L,c);
		 }
};
}

