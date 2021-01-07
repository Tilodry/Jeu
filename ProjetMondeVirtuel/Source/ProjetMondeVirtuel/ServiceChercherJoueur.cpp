// Fill out your copyright notice in the Description page of Project Settings.


#include "ServiceChercherJoueur.h"
#include "Kismet/GameplayStatics.h"
#include "DroneAI.h"
#include "Drone.h"
#include "GameFramework/CharacterMovementComponent.h"



UServiceChercherJoueur::UServiceChercherJoueur() {
	this->bCreateNodeInstance = true;
	UE_LOG(LogTemp, Warning, TEXT("Recherche de checkpoints ... %d checkpoints trouves"), this->recupererListeCheckpoint());
}

void UServiceChercherJoueur::TickNode(UBehaviorTreeComponent& proprietaire, uint8* noeudMemoire, float deltaSeconde) 
{
	ADroneAI* droneAI = Cast<ADroneAI>(proprietaire.GetAIOwner());
	if (droneAI) 
	{
		//UE_LOG(LogTemp, Warning, TEXT("Passage dans cette boucle l.21 ServiceChercherJoueusdrgdrgdrgdrgdrg"))
		//POUR CHECKPOINT
		//if (proprietaire.GetBlackboardComponent()->GetValue<UBlackboardKeyType_Object>(droneAI->aRejointCle))
		if (droneAI->getDrone()->possedeCible)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Le drone possede une cible, je m'y dirige"))
			proprietaire.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(droneAI->ennemiCle, droneAI->getDrone()->cible);
			proprietaire.GetBlackboardComponent()->SetValueAsBool(FName("aRejointCible"), false);
		}
		else if (proprietaire.GetBlackboardComponent()->GetValueAsBool(FName("aRejointCible")))
		{
			if (this->indexDeCheckpoint < this->listeCheckpoint.Num() - 1)
			{
				this->indexDeCheckpoint = FMath::RandRange(0, listeCheckpoint.Num() - 1);
				droneAI->getDrone()->GetCharacterMovement()->MaxWalkSpeed += 0.1;
				droneAI->getDrone()->GetCharacterMovement()->MaxAcceleration += 0.1;
				//this->indexDeCheckpoint++;
				proprietaire.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(droneAI->ennemiCle, this->listeCheckpoint[this->indexDeCheckpoint]);
			}
			else
			{
				//droneAI->drone->GetCharacterMovement()->MaxWalkSpeed /= 2;
				this->indexDeCheckpoint = 0;
				proprietaire.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(droneAI->ennemiCle, this->listeCheckpoint[this->indexDeCheckpoint]);
			}
			proprietaire.GetBlackboardComponent()->SetValueAsBool(FName("aRejointCible"), false);
		}
		else {
			proprietaire.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(droneAI->ennemiCle, this->listeCheckpoint[this->indexDeCheckpoint]);
		}
		//POUR JOUEUR
		/*AProjetMondeVirtuelCharacter* cible = Cast<AProjetMondeVirtuelCharacter>(GetWorld()->GetFirstPlayerController()->GetPawn());
		if (cible) 
		{
			proprietaire.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(droneAI->ennemiCle, cible);
		}*/
	}
}

int8 UServiceChercherJoueur::recupererListeCheckpoint() {
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), FName(TEXT("CheckpointPatrouille")), this->listeCheckpoint);
	return this->listeCheckpoint.Num();
}