import javafx.application.*;
import javafx.stage.*;
import javafx.scene.*;
import javafx.scene.control.*;
import javafx.layout.scene.layout.*;

public class App extends Application {
    private Button bt;
    public static void main(String[] args) {
        launch(args);
    } 
}
public void start(Stage stage)throws Exception {
    bt=new Botton();
    bt.setText("Hi");
    BorderPane bp=new BorderPane();
    //add Button to Pane;
    bp.setCenter(bt);
    Scene cs=new Scene(bp, 300, 200);
    stage.setScene(sc);
    stage.steTitle("Sample");
    stage.show();
}