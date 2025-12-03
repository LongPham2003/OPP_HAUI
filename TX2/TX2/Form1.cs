using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace TX2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label4_Click(object sender, EventArgs e)
        {

        }

        DataUtil dataUtil = new DataUtil();

        /// Hiển thị dữ liệu lên DataGridView
        public void displayData()
        {
            List<Sach> list_sach = dataUtil.getAllData();
            dgvData.DataSource = list_sach;
            dgvData.Columns[0].Width = 100;
            dgvData.Columns[1].Width = 100;
            dgvData.Columns[2].Width = 100;
            dgvData.Columns[3].Width = 100;
            dgvData.Columns[4].Width = 100;
            dgvData.Columns[0].HeaderText = "Mã Sách";
            dgvData.Columns[1].HeaderText = "Tên Sách";
            dgvData.Columns[2].HeaderText = "Số Trang";
            dgvData.Columns[3].HeaderText = "Họ Tên Tác Giả";
            dgvData.Columns[4].HeaderText = "Địa Chỉ Tác Giả";
            dgvData.ReadOnly = true;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            displayData();
        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        /// thêm sản phẩm 
      
        private void button1_Click(object sender, EventArgs e)
        {
            Sach s  =new Sach();
            s.maSach = txtMaSach.Text;
            s.tenSach = txtTenSach.Text;
            s.soTrang = int.Parse( txtSoTrang.Text);
            s.hoTenTacGia = txtTenTacGia.Text;
            s.diaChiTacGia = txtDiaChi.Text;
            if (dataUtil.addSach(s))
            {
                MessageBox.Show("Thêm sách thành công");
                displayData();
            }
            else
            {
                MessageBox.Show("Thêm sách thất bại. Mã sách đã tồn tại");
            }
        }
        /// click vào dòng nào hiện dữ liệu lên textbox
        private void cellClick(object sender, DataGridViewCellEventArgs e)
        {
            Sach sachChoose = (Sach)dgvData.CurrentRow.DataBoundItem;
            txtMaSach.Text = sachChoose.maSach;
            txtTenSach.Text = sachChoose.tenSach;
            txtSoTrang.Text = sachChoose.soTrang.ToString();
            txtTenTacGia.Text = sachChoose.hoTenTacGia;
            txtDiaChi.Text = sachChoose.diaChiTacGia;

        }
        /// clear hết dữ liệu trên textbox 
        private void button2_Click(object sender, EventArgs e)
        {
            txtMaSach.Text = "";
            txtTenSach.Text = "";
            txtSoTrang.Text = "";
            txtTenTacGia.Text = "";
            txtDiaChi.Text = "";
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string id = txtMaSach.Text;
            DialogResult d = MessageBox.Show($"Bạn có muốn xóa sách có id ={id} không?",
                "Xác nhận xóa", MessageBoxButtons.YesNo, MessageBoxIcon.Question);

            if (d == DialogResult.Yes)
            {
                if (dataUtil.deleteSach(id))
                {
                    MessageBox.Show("Xóa sách thành công");
                    displayData();
                }
                else
                {
                    MessageBox.Show("Xóa sách thất bại. Mã sách không tồn tại");
                }
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            Sach s = new Sach()
            {
                maSach = txtMaSach.Text,
                tenSach = txtTenSach.Text,
                soTrang = int.Parse(txtSoTrang.Text),
                hoTenTacGia = txtTenTacGia.Text,
                diaChiTacGia = txtDiaChi.Text
            };

            if (dataUtil.updateSach(s))
            {
                MessageBox.Show("Cập nhật sách thành công!");
                displayData();
            }
            else
            {
                MessageBox.Show("Cập nhật sách thất bại. Không tìm thấy Mã Sách hoặc lỗi xảy ra.");
            }
        }
    }
}
