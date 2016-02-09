using UnityEngine;
using System.Collections;
using System.IO.Ports;

public class Movements : MonoBehaviour {

    //public string PortToUse = "COM4";

    SerialPort sp = new SerialPort("COM4", 9600);
    public string data;

    public long doigt1;
    public long doigt2;
    public long doigt3;
    public long doigt4;
    public long doigt5;

    public long AX;
    public long AY;
    public long AZ;
    public long GX;
    public long GY;
    public long GZ;

    public float playerSpeed = 5.0f;
	// Use this for initialization
	void Start () {
        sp.Open();
        sp.ReadTimeout = 1;

        transform.position = new Vector3(0, 2, -3);

	}
	
	// Update is called once per frame
	void Update () {

        data = sp.ReadLine();

        doigt1 = data[1];


        transform.Translate(Vector3.right * Input.GetAxis("Horizontal") * playerSpeed * Time.deltaTime);
        transform.Translate(Vector3.up * Input.GetAxis("Vertical") * playerSpeed * Time.deltaTime);

        if (sp.IsOpen)
        {
            try
            {
                MoveObject(sp.ReadByte());
                print(sp.ReadByte());
            }
            catch(System.Exception)
            { 
            
            }
        }
	}

    void MoveObject(int Direction)
    {
        if (Direction == 1)
        { 
        
        }
    }

}
