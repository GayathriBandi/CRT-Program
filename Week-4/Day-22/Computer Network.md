# 📘 Computer Networks 
## 🔶 1. Basics of Computer Networks
- **Computer Network:** A system of interconnected computers/devices that communicate with each other to share resources, data, and applications.
- **Key Objectives:**
  - Efficient communication (emails, messages)
  - Resource sharing (files, printers, internet)
  - Cost reduction and centralized data management
  - Scalability, fault tolerance, and backup support
- **Types of Networks:**
  - **LAN (Local Area Network):** Small geographical area; high speed (100Mbps to 1Gbps); e.g., office/home.
  - **MAN (Metropolitan Area Network):** Covers a city; e.g., cable TV networks.
  - **WAN (Wide Area Network):** Covers large regions/countries (e.g., Internet).
  - **PAN (Personal Area Network):** Limited to personal devices (e.g., Bluetooth, USB tethering).

---

## 🔶 2. Network Topologies
- **Topology:** The physical or logical layout of network devices.
- **Types:**
  - **Star Topology:** Central hub; easy to manage; failure of hub disrupts entire network.
  - **Bus Topology:** Single cable backbone; cost-effective; collision-prone.
  - **Ring Topology:** Nodes form a loop; data flows in one direction; token-passing.
  - **Mesh Topology:** Every device connects to every other; redundant; expensive.
  - **Hybrid Topology:** Mix of above; commonly used in real-world large networks.

---

## 🔶 3. OSI Model – 7 Layers Explained
| Layer | Description | Protocols/Devices |
|-------|-------------|-------------------|
| 7. **Application** | Interface for users/apps to access network | HTTP, FTP, SMTP |
| 6. **Presentation** | Translates, encrypts, compresses data | JPEG, SSL, ASCII |
| 5. **Session** | Manages session setup and teardown | NetBIOS, RPC |
| 4. **Transport** | End-to-end connection, flow & error control | TCP, UDP |
| 3. **Network** | Routing, addressing, logical paths | IP, ICMP, Routers |
| 2. **Data Link** | Frame creation, MAC, switches | Ethernet, ARP |
| 1. **Physical** | Transmission of raw bits | Cables, Hubs, NIC |

---

## 🔶 4. TCP/IP Model (4 Layers)
- A simplified, practical model for networking.
- **Layers:**
  1. **Application Layer** – Web, Email, DNS
  2. **Transport Layer** – TCP (reliable), UDP (fast)
  3. **Internet Layer** – IP, ICMP
  4. **Network Access Layer** – Ethernet, Wi-Fi, MAC

---

## 🔶 5. IP Addressing
- **IPv4:** 32-bit; written in dotted decimal (e.g., 192.168.0.1)
- **IPv6:** 128-bit; hex format; solves IPv4 exhaustion (e.g., 2001:db8::1)
- **Address Classes:**
  - **A:** 0–127 (large networks)
  - **B:** 128–191 (medium networks)
  - **C:** 192–223 (small networks)
  - **D:** 224–239 (multicast)
  - **E:** 240–255 (research/reserved)

---

## 🔶 6. Subnetting (With Example)
- Breaks a large network into smaller networks.
- **Example:**
  - IP: 192.168.1.0/24 → Subnet Mask: 255.255.255.0
  - Subnet into 4 → /26 mask → each block = 64 addresses
- **Benefits:**
  - Better security
  - Efficient IP usage
  - Improved performance

---

## 🔶 7. Protocols in Networking
- **TCP (Transmission Control Protocol):**
  - Connection-oriented
  - Guarantees delivery and order
  - Used in email, file transfers, web pages
- **UDP (User Datagram Protocol):**
  - Connectionless
  - Faster but no reliability (used in live streaming, DNS)
- **HTTP/HTTPS:** Web data transfer (Hypertext Transfer Protocol + Secure)
- **FTP (File Transfer Protocol):** Transfers files between client-server
- **DNS (Domain Name System):** Converts domain to IP (e.g., google.com → 142.250.x.x)
- **SMTP/POP3/IMAP:** Mail sending and retrieval
- **SNMP:** Network device monitoring
- **ICMP:** Used by ping/traceroute for diagnostics

---

## 🔶 8. Networking Devices
| Device  | Function |
|---------|----------|
| **Router** | Connects multiple networks; routes data |
| **Switch** | Connects devices in LAN; intelligent forwarding |
| **Hub** | Basic broadcaster; sends data to all |
| **Bridge** | Connects LANs; filters traffic |
| **Modem** | Converts analog to digital (ISP use) |
| **Gateway** | Translates between protocols |

---

## 🔶 9. Transmission Modes
- **Simplex:** One-way only (e.g., keyboard to computer)
- **Half-Duplex:** Two-way, one at a time (e.g., walkie-talkie)
- **Full-Duplex:** Both ways at once (e.g., phone call)

---

## 🔶 10. Transmission Media
- **Wired Media:**
  - Twisted Pair: Cheap, common in LANs
  - Coaxial Cable: Cable TV, better shielded
  - Optical Fiber: High speed, long distance
- **Wireless Media:**
  - Radio Waves: Wi-Fi, cellular
  - Infrared: TV remotes
  - Bluetooth: PAN devices

---

## 🔶 11. Switching Techniques
- **Circuit Switching:**
  - Dedicated path for entire call
  - Used in traditional phone networks
- **Packet Switching:**
  - Data sent in packets
  - Each packet may take a different route
  - Used in Internet
- **Message Switching:** Store-and-forward whole messages (inefficient, outdated)

---

## 🔶 12. Error Detection & Correction Techniques
- **Parity Bits:** Simple bit check (even/odd)
- **CRC (Cyclic Redundancy Check):** Polynomial-based error detection
- **Checksum:** Adds up bits for integrity check
- **Hamming Code:** Detects and corrects 1-bit errors

---

## 🔶 13. MAC vs IP Address
- **MAC Address:**
  - Physical hardware address
  - Permanent, Layer 2
  - e.g., 00:1A:2B:3C:4D:5E
- **IP Address:**
  - Logical address assigned to devices
  - Can change; Layer 3
  - e.g., 192.168.1.1

---

## 🔶 14. DNS and DHCP
- **DNS (Domain Name System):** Maps domain names to IPs (like a phonebook).
- **DHCP (Dynamic Host Configuration Protocol):** Automatically assigns IPs to devices in a network.

---

## 🔶 15. Network Security Basics
- **Firewall:** Blocks unauthorized access
- **Antivirus/IDS/IPS:** Detects and prevents attacks
- **Encryption (SSL/TLS):** Secures data in transit
- **VPN (Virtual Private Network):** Creates a secure tunnel over the Internet
- **Authentication Methods:** Passwords, OTPs, 2FA

---

## 🔶 16. Important Port Numbers
| Service  | Port |
|----------|------|
| HTTP     | 80   |
| HTTPS    | 443  |
| FTP      | 21   |
| SSH      | 22   |
| DNS      | 53   |
| SMTP     | 25   |
| DHCP     | 67 (Server), 68 (Client) |

---

## 🔶 17. Network Commands (Linux/Windows)
- `ping`: Check connectivity
- `tracert` / `traceroute`: Show route taken by packets
- `ipconfig` / `ifconfig`: View IP and network info
- `netstat`: View network connections
- `nslookup`: Query DNS records

---

## 🔶 18. Network Models Comparison

| Feature        | OSI Model             | TCP/IP Model         |
|----------------|------------------------|------------------------|
| Layers         | 7                      | 4                      |
| Developed By   | ISO                    | DARPA (US Dept.)      |
| Protocol Tightness | Loose           | Protocol-specific     |
| Popularity     | Theoretical reference  | Real-world model      |

---
