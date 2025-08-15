# 🕰️ Hollow Clock – Đồng Hồ Lơ Lửng với ESP32

Dự án này hiện thực một chiếc **đồng hồ lơ lửng (hollow clock)** sử dụng động cơ bước và ESP32 để hiển thị thời gian một cách trực quan, độc đáo thông qua cơ cấu truyền động bánh răng.

---

## 🧰 Phần cứng sử dụng

- 📡 **ESP32-C3 SuperMini** – Vi điều khiển kết nối WiFi
- 🔄 **Động cơ bước 28BYJ-48** – 2048 bước/vòng (chế độ full-step)
- ⚙️ **Driver ULN2003** – Mạch điều khiển động cơ bước
- 🪛 **Cơ cấu truyền động bánh răng** – Gồm bánh răng thẳng và nghiêng

---

## ⚙️ Nguyên lý hoạt động

- Động cơ hoạt động ở **chế độ full-step**: 1 vòng = **2048 bước**
- Cơ cấu bánh răng gồm:
  - **Bánh răng phút**: 90 răng, dẫn động qua **bánh răng thẳng 12 răng** gắn trên trục động cơ
    - → **Tỉ số truyền i = 90 / 12 = 7.5**
  - **Bánh răng giờ**: 90 răng, truyền động gián tiếp với tỉ số **i = 90**

Từ đó ta có:
- Khi động cơ quay 7.5 vòng → bánh răng phút quay được 1 vòng (360°)
- Bánh răng phút quay 12 vòng → bánh răng giờ quay 1 vòng
  - Phù hợp với thực tế: 60 phút (kim phút quay 1 vòng) → kim giờ quay 1/12 vòng

---

## 🔁 Nguyên lý điều khiển

- 1 vòng = **360° = 60 phút** → mỗi phút kim phút dịch chuyển **6°**
- Cần tính số bước động cơ để kim phút quay được 6°, có:

```text
Góc quay động cơ = 6° (kim phút) × 7.5 (tỉ số truyền) = 45°
Mỗi bước động cơ = 360° / 2048 ≈ 0.1758°
Số bước cần = 45 / 0.1758 ≈ 256 bước

## Chú ý nếu cấu hình thời gian là sau 6h thì đồng hồ setup ở chế độ 6:00
