package com.example.parcial2corte;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.widget.TextView;

public class MainActivity2 extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main2);

        TextView CantCebo = findViewById(R.id.Text6);
        TextView CantManz = findViewById(R.id.Text10);
        TextView CantPapa = findViewById(R.id.Text14);
        TextView CantPinya = findViewById(R.id.Text18);

        TextView TotalCebo = findViewById(R.id.Text8);
        TextView TotalManz = findViewById(R.id.Text12);
        TextView TotalPapa = findViewById(R.id.Text16);
        TextView TotalPinya = findViewById(R.id.Text20);

        TextView Subtotal = findViewById(R.id.textView3);
        TextView IVA = findViewById(R.id.textView5);
        TextView Total = findViewById(R.id.textView7);

        Bundle extras = getIntent().getExtras();

        int Cebollas = extras.getInt("Cebo");
        int Manzanas = extras.getInt("Manz");
        int Papas = extras.getInt("Papa");
        int Pinyas = extras.getInt("Pinyas");

        CantCebo.setText(String.valueOf(Cebollas));
        CantManz.setText(String.valueOf(Manzanas));
        CantPapa.setText(String.valueOf(Papas));
        CantPinya.setText(String.valueOf(Pinyas));

        int PrecioCebollas = Cebollas * 500;
        int PrecioManzanas = Manzanas * 1200;
        int PrecioPapas = Papas * 350;
        int PrecioPinyas = Pinyas * 5500;

        TotalCebo.setText(String.valueOf(PrecioCebollas));
        TotalManz.setText(String.valueOf(PrecioManzanas));
        TotalPapa.setText(String.valueOf(PrecioPapas));
        TotalPinya.setText(String.valueOf(PrecioPinyas));

        int subtotalint = PrecioCebollas+PrecioManzanas+PrecioPapas+PrecioPinyas;
        double IVAbef = subtotalint*0.19;
        double Totalint = IVAbef+subtotalint;

        Subtotal.setText(String.valueOf(subtotalint));
        IVA.setText(String.valueOf(IVAbef));
        Total.setText(String.valueOf(Totalint));

    }
}