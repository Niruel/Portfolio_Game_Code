using UnityEngine;

public class UIEvents : MonoBehaviour {
    private Canvas CanvasObject;
    

    void Start()
    {
        CanvasObject = GetComponent<Canvas>();
        CanvasObject.enabled = false;
        Cursor.visible = false;
    }

    void Update()
    {

        if (Input.GetKeyDown(KeyCode.Escape))
        {
            CanvasObject.enabled = !CanvasObject.enabled;
            Cursor.visible = !Cursor.visible;

        }
        if (Input.touchCount > 0 && Input.GetTouch(1).phase == TouchPhase.Began)
        {
            CanvasObject.enabled = !CanvasObject.enabled;
        }
    }
    public void Resume()
    {
        CanvasObject.enabled = false;
        Cursor.visible = false;
    }
    public void Quit()
    {
        Application.Quit();

    }
  
}
