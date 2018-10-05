using UnityEngine;
using UnityEngine.UI;


public class YSlider : MonoBehaviour {
 
    //public GameObject line;
    public Slider zoomSlider;

    // Update is called once per frame
    void Awake()
    {
        if (zoomSlider)
        {
            Camera.main.fieldOfView = PlayerPrefs.GetFloat("curZoom");
            zoomSlider.value = Camera.main.fieldOfView;
        }
       
    }

    public void Zoom(float zoomDist)
    {
        Camera.main.fieldOfView = zoomDist;
        PlayerPrefs.SetFloat("curZoom", Camera.main.fieldOfView);
    }
}
