import javafx.application.*;
import java.stage.*;
import javafx.scene.control.*;
import javafx.scene.layout.*;

public class App extends Application {
    private Lavel lb;
    
    public static void main(String[] args) {
        launch(args);
    }
}
@Override
public void start(Stage stage)throws Exception {
    //make Control
    lb=new Label();
    //set Control
    lb.setText("Hello");
    //make Pane
    BorderPane bp=new BorderPane();
    //add Control to Pane
    bp.setCenter(lb);
    //make Scene
    Scene sc=new Scene(bp, 300, 200);
    //add Scene to Stage
    stage.setScene(sc);
    //represent stage
    stage.setTitle("Sample");
    stage.show();
}