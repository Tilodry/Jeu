// Fill out your copyright notice in the Description page of Project Settings.


#include "coneDeRecherche.h"

UconeDeRecherche::UconeDeRecherche() {
	static ConstructorHelpers::FObjectFinder<UStaticMesh>coneMeshAsset(TEXT("StaticMesh'/Engine/BasicShapes/Cone.Cone'"));
	this->SetStaticMesh(coneMeshAsset.Object);
	this->SetWorldScale3D(FVector(3, 3, 3));
	this->OnComponentBeginOverlap.AddDynamic(this, &UconeDeRecherche::BeginOverlap);
}

void UconeDeRecherche::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{ // Quand une cible rentre dans la lumière on la désigne comme nouvelle cible
	/*if (Cast<AMondeVirtuelCharacter>(OtherActor))
	{
		//FAIRE RAYCAST POUR VERIFIER
		if (envoyerRaycast(OtherActor->GetActorLocation()))
		{
			UE_LOG(LogTemp, Warning, TEXT("PASSER ICI"));
			positionInitiale = coneDeRecherche->GetRelativeTransform(); // On enregistre notre position initiale pour pouvoir s'y remettre une fois la cible perdue
			cible = OtherActor; // On actualise notre membre cible avec la nouvelle cible
			possedeCible = true; // On indique qu'on possède désormais une cible
			FString touche = "Quelqu'un rentre dans mon champs de vision, c'est : " + OtherActor->GetName() + " a la position : " + OtherActor->GetTargetLocation().ToString();
			UE_LOG(LogTemp, Warning, TEXT("%s"), *touche);
		}

	}*/
}