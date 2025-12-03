using System;
using System.Collections.Generic;
using System.IO;
using System.Xml;

namespace TX2
{
    internal class DataUtil
    {
        XmlElement root;
        XmlDocument doc;
        string path;

        public DataUtil()
        {
            path = "../../ThuVien.xml";
            doc = new XmlDocument();    
            if(!File.Exists(path))
            {
                XmlElement tv = doc.CreateElement("ThuVien");
                doc.AppendChild(tv);
                doc.Save(path);
            }
            else
            {
                doc.Load(path);
                root = doc.DocumentElement;
            }
        }

        // lay tat ca du lieu
        public List<Sach> getAllData()
        {
            XmlNodeList node_list_data = root.SelectNodes("Sach");
            List<Sach> list_sach = new List<Sach>();
            foreach(XmlNode node in node_list_data)
            {
                Sach s = new Sach();
                s.maSach = node.Attributes["masach"].Value;
                s.tenSach = node.SelectSingleNode("TenSach").InnerText;
                s.soTrang = int.Parse( node.SelectSingleNode("SoTrang").InnerText);
                XmlNode tg = node.SelectSingleNode("TacGia");
                s.hoTenTacGia = tg.SelectSingleNode("HoTen").InnerText; 
                s.diaChiTacGia = tg.SelectSingleNode("DiaChi").InnerText;
                list_sach.Add(s);
            }
            return list_sach;
        }
        // them sach
        public bool addSach(Sach s)
        {
            XmlNode sachFind = root.SelectSingleNode($"Sach[@masach='{s.maSach}']");
            if(sachFind != null)
            {
                return false;
            }
            XmlElement sach = doc.CreateElement("Sach");
            XmlElement tensach = doc.CreateElement("TenSach");
            XmlElement sotrang = doc.CreateElement("SoTrang");
            XmlElement tacgia = doc.CreateElement("TacGia");
            XmlElement hoten = doc.CreateElement("HoTen");
            XmlElement diachi = doc.CreateElement("DiaChi");
            sach.SetAttribute("masach", s.maSach);
            tensach.InnerText = s.tenSach;
            sotrang.InnerText = s.soTrang.ToString();
            hoten.InnerText = s.hoTenTacGia;
            diachi.InnerText = s.diaChiTacGia;
            tacgia.AppendChild(hoten);
            tacgia.AppendChild(diachi);
            sach.AppendChild(tensach);  
            sach.AppendChild(sotrang);
            sach.AppendChild(tacgia);
            root.AppendChild(sach);
            doc.Save(path);
            return true;
        }

        // xoa sach
        public bool deleteSach(string maSach)
        {
            XmlNode sachFind = root.SelectSingleNode($"Sach[@masach='{maSach}']");
            if(sachFind == null)
            {
                return false;
            }
            root.RemoveChild(sachFind);
            doc.Save(path);
            return true;
        }
        //cap nhat sach
        public bool updateSach(Sach s)
        {
            XmlNode sachFind = root.SelectSingleNode($"Sach[@masach='{s.maSach}']");
            if (sachFind == null)
            {
                return false;
            }
            sachFind.SelectSingleNode("TenSach").InnerText = s.tenSach;
            sachFind.SelectSingleNode("SoTrang").InnerText = s.soTrang.ToString();
            XmlNode tg = sachFind.SelectSingleNode("TacGia");
            tg.SelectSingleNode("HoTen").InnerText = s.hoTenTacGia;
            tg.SelectSingleNode("DiaChi").InnerText = s.diaChiTacGia;
            doc.Save(path); 
            return true;
        }
    }
}
