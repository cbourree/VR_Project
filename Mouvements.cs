using UnityEngine;
using System.Collections;
using System.IO.Ports;


public class Mouvements : MonoBehaviour
{

    //public string PortToUse = "COM4";

    SerialPort sp = new SerialPort("COM4", 9600);
    public string data;

    public double doigt1;
	public double doigt2;
	public double doigt3;
	public double doigt4;
	public double doigt5;

	public float AX;
	public float AY;
	public float AZ;
	public float GX;
	public float GY;
	public float GZ;

	private float OffsetAX, OffsetAY, OffsetAZ;

	public GameObject Cube;

    
    void Start()
    {
		try
		{
			sp.Open();
			sp.ReadTimeout = 15;
		}
		catch (System.Exception)
		{
			Debug.Log ("Impossible d'ouvrir le port COM4");
		}
		OffsetAX = 0;
		OffsetAY = 0;
		OffsetAZ = 0;
    }

    // Update is called once per frame
    void Update()
    {
		if (Input.GetKeyDown(KeyCode.I)) {
			InitialisationGyro ();
		}

        if (sp.IsOpen)
        {
			

            try
            {
				
				data = sp.ReadLine();
				doigt1 = (data[1] - '0') + ((data[3] - '0') * 0.1) + ((data[4] - '0') * 0.01);
				doigt2 = (data[7] - '0') + ((data[9] - '0') * 0.1) + ((data[10] - '0') * 0.01);
				doigt3 = (data[13] - '0') + ((data[15] - '0')*0.1) + ((data[16] - '0') * 0.01);
				doigt4 = (data[19] - '0') + ((data[21] - '0')*0.1) + ((data[22] - '0') * 0.01);

				AX = ((data[27] - '0')*10000) + ((data[28] - '0') * 1000) + ((data[29] - '0') * 100) + ((data[30] - '0') * 10) + ((data[31] - '0'));
				AX = ((data[26]) == '-') ? -AX : AX;
				AX = (((AX + 16000) * 180) / 32000); 

				AY = ((data[37] - '0')*10000) + ((data[38] - '0') * 1000) + ((data[39] - '0') * 100) + ((data[40] - '0') * 10) + ((data[41] - '0'));
				AY = ((data[36]) == '-') ? -AY : AY;
				AY = (((AY + 16000) * 180) / 32000);

				AZ = ((data[47] - '0')*10000) + ((data[48] - '0') * 1000) + ((data[49] - '0') * 100) + ((data[50] - '0') * 10) + ((data[51] - '0'));
				AZ = ((data[46]) == '-') ? -AZ : AZ;
				AZ = (((AZ + 16000) * 180) / 32000);
				//Debug.Log ("Offset AX : " + OffsetAX + " AY : " + OffsetAY + " AZ : " + OffsetAZ);
				Debug.Log ("Result AX : " + (AX - OffsetAX) + " AY : " + (AZ - OffsetAZ) + " AZ : " + (AZ - OffsetAZ));
				MoveObject(AX - OffsetAX, AY - OffsetAY, AZ - OffsetAZ, Cube);

				GX = ((data[57] - '0')*10000) + ((data[58] - '0') * 1000) + ((data[59] - '0') * 100) + ((data[60] - '0') * 10) + ((data[61] - '0'));
				GX = ((data[26] - '0') == '-') ? -GX : GX;

				GY = ((data[67] - '0')*10000) + ((data[68] - '0') * 1000) + ((data[69] - '0') * 100) + ((data[70] - '0') * 10) + ((data[71] - '0'));
				GY = ((data[26] - '0') == '-') ? -GY : GY;

				GZ = ((data[77] - '0')*10000) + ((data[78] - '0') * 1000) + ((data[79] - '0') * 100) + ((data[80] - '0') * 10) + ((data[81] - '0'));
				GZ = ((data[26] - '0') == '-') ? -GZ : GZ;



            }
            catch (System.Exception)
            {
				Debug.Log ("Impossible de lire la liaison série");
            }
        }
    }
		
	void MoveObject(float valueX, float valueY, float valueZ, GameObject ObjectToMove)
    {
		//ObjectToMove.transform.eulerAngles = new Vector3 ((valueX - 90) * 0.9f, 0, 0);
		ObjectToMove.transform.eulerAngles = new Vector3 ((valueX) * 0.9f, (valueY) * 0.9f, (valueZ) * 0.9f);

    }

	void InitialisationGyro()
	{
		try
		{
			data = sp.ReadLine();
			AX = ((data[27] - '0')*10000) + ((data[28] - '0') * 1000) + ((data[29] - '0') * 100) + ((data[30] - '0') * 10) + ((data[31] - '0'));
			AX = ((data[26]) == '-') ? -AX : AX;
			OffsetAX = (((AX + 16000) * 180) / 32000); 

			AY = ((data[37] - '0')*10000) + ((data[38] - '0') * 1000) + ((data[39] - '0') * 100) + ((data[40] - '0') * 10) + ((data[41] - '0'));
			AY = ((data[36]) == '-') ? -AY : AY;
			OffsetAY = (((AY + 16000) * 180) / 32000);

			AZ = ((data[47] - '0')*10000) + ((data[48] - '0') * 1000) + ((data[49] - '0') * 100) + ((data[50] - '0') * 10) + ((data[51] - '0'));
			AZ = ((data[46]) == '-') ? -AZ : AZ;
			OffsetAZ = (((AZ + 16000) * 180) / 32000);

			//MoveObject(OffsetAX, OffsetAY, OffsetAZ, Cube);

			Debug.Log ("Initialisation... Offset AX : " + OffsetAX + " AY : " + OffsetAY + " AZ : " + OffsetAZ);
		}
		catch (System.Exception)
		{
			Debug.Log ("Impossible de lire la liaison série");
		}
	}

}
