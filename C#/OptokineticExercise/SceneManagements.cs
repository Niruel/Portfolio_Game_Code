using System.Collections;
using System.Collections.Generic;
using UnityEngine.SceneManagement;
using UnityEngine;

public class SceneManagements : MonoBehaviour {

    public void Horozontal(bool loadScene)
    {
        if (loadScene)
        {
            SceneManager.LoadScene("OptoHorozontal");
        }
    }
    public void RHorozontal(bool loadScene)
    {
        if (loadScene)
        {
            SceneManager.LoadScene("OptoHorozontal 1");
        }
    }
    public void Vertical(bool loadScene)
    {
        if (loadScene)
        {
            SceneManager.LoadScene("OpoVertical");
            SpeedManager.instance.guyList.Clear();
        }
    }
    public void RVertical(bool loadScene)
    {
        if (loadScene)
        {
            SceneManager.LoadScene("OpoVertical 1");
            SpeedManager.instance.guyList.Clear();
        }
    }
    public void Diagonal(bool loadScene)
    {
        if (loadScene)
        {
            SceneManager.LoadScene("OptoDiagonal");
        }
    }
    public void RDiagonal(bool loadScene)
    {
        if (loadScene)
        {
            SceneManager.LoadScene("OptoDiagonal 1");
        }
    }
    public void LoadRandomScene()
    {
       
        SceneManager.LoadScene("OpoVertical 1");
    }
    public void Quit()
    {
        Application.Quit();

    }
}
