package com.example.parcial2corte;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.os.Bundle;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView CebollasView = findViewById(R.id.CantCebo);
        TextView ManzanasView = findViewById(R.id.CantManz);
        TextView PapasView = findViewById(R.id.CantPapa);
        TextView PinyasView = findViewById(R.id.CantPiña);

        Button CambiarAFactura = findViewById(R.id.MFactura);

        CambiarAFactura.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {

                    String CebollasString = CebollasView.getText().toString().trim();
                    String ManzanasString = ManzanasView.getText().toString().trim();
                    String PapasString = PapasView.getText().toString().trim();
                    String PinyasString = PinyasView.getText().toString().trim();

                    int Cebollas = Integer.parseInt(CebollasString);
                    int Manzanas = Integer.parseInt(ManzanasString);
                    int Papas = Integer.parseInt(PapasString);
                    int Pinyas = Integer.parseInt(PinyasString);
                    Intent calc = new Intent(MainActivity.this, MainActivity2.class );
                    Bundle Pack = new Bundle();


                    Pack.putInt("Cebo", Cebollas);
                    Pack.putInt("Manz", Manzanas);
                    Pack.putInt("Papa", Papas);
                    Pack.putInt("Pinyas", Pinyas);

                    calc.putExtras(Pack);

                    startActivity(calc);

                } catch (Exception e){

                    Toast.makeText(getApplicationContext(), "Hubo un error. Intente nuevamente.", Toast.LENGTH_SHORT).show();
                }


            }
        });

    }
}