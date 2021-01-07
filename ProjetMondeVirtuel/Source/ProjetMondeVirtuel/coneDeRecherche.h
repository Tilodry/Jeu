// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "coneDeRecherche.generated.h"

/**
 * 
 */
UCLASS()
class PROJETMONDEVIRTUEL_API UconeDeRecherche : public UStaticMeshComponent
{
	GENERATED_BODY()
public:

	UconeDeRecherche();

	UFUNCTION()
		void BeginOverlap(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex,
			bool bFromSweep,
			const FHitResult& SweepResult);
};
