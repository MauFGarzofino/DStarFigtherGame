// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveJugador.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
ANaveJugador::ANaveJugador()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SM_NaveJugador = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SM NaveJugador"));
	RootComponent = SM_NaveJugador;

	//Tenemos que configurar cosas, que tienen que ver con el motor de físicas.  

	SM_NaveJugador->SetEnableGravity(false); //Para que el objeto no se vaya para abajo por la f de la gravedad
	SM_NaveJugador->SetConstraintMode(EDOFMode::XZPlane); //Que solo trabaja en los ejes X Z del plano
	SM_NaveJugador->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); //La nave, asuma el modo de restricción, controlando las condiciones físicas(se agregan por sí solas) y las del lugar(Hay que agregarlas)
	SM_NaveJugador->SetCollisionProfileName(TEXT("PhisicActor")); // Le damos un nombre a esta configuración de colisión

	// Todo eso lo necesito para que la nave aparezca en el unreal, pueda modificarlo

	FloatingMovement = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement"));
	// Creamos 


}

// Called when the game starts or when spawned
void ANaveJugador::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveJugador::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANaveJugador::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ANaveJugador::MoveHorizontal(float AxisValue1)
{
	//Lamma al método AddMovementInput , que agregue a las entradas del objeto que éstá captando 'pawn'
	AddMovementInput(FVector(AxisValue1, 0.0f, 0.0f), 1.0f, false);
	//Sin escala (1.0) y false porque no queremos forzar nada
	//Crea un vector con el valor que le pasaremos en el  eje X
}

void ANaveJugador::MoveVertical(float AxisValue2)
{
	AddMovementInput(FVector(0.0f, 0.0f, AxisValue2), 1.0f, false);
}

