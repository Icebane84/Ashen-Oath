// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "EnvQueryContext_CompanionSpot.h"
#include "AshenCompanionAIComponent.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "EnvironmentQuery/Items/EnvQueryItemType_Point.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"

void UEnvQueryContext_CompanionSpot::ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	AActor* Querier = Cast<AActor>(QueryInstance.Owner.Get());
	if (!Querier)
	{
		return;
	}

	UAshenCompanionAIComponent* CompanionAI = Querier->FindComponentByClass<UAshenCompanionAIComponent>();
	if (!CompanionAI)
	{
		// Default: provide flank spots if no companion AI found
		ProvideFlanкSpots(QueryInstance, ContextData);
		return;
	}

	switch (CompanionAI->CurrentAIState)
	{
	case EAshenCompanionAIState::OffensiveSupport:
	case EAshenCompanionAIState::TacticalTriage:
		ProvideFlanкSpots(QueryInstance, ContextData);
		break;

	case EAshenCompanionAIState::UnchainedContainment:
		ProvideTrapSpots(QueryInstance, ContextData);
		break;

	case EAshenCompanionAIState::RecoveryAnchoring:
		ProvideSanctuaryAnchorSpots(QueryInstance, ContextData);
		break;
	}
}

void UEnvQueryContext_CompanionSpot::ProvideFlanкSpots(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	AActor* Querier = Cast<AActor>(QueryInstance.Owner.Get());
	if (!Querier) { return; }

	// Resolve primary target (player pawn) for flank offset calculation
	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(Querier->GetWorld(), 0);
	if (!PlayerPawn) { return; }

	FVector EnemyLoc = Querier->GetActorLocation();
	FVector ToPlayer = (PlayerPawn->GetActorLocation() - EnemyLoc).GetSafeNormal();
	FVector RightFlank = FVector::CrossProduct(ToPlayer, FVector::UpVector).GetSafeNormal();

	// Two lateral flank positions at 400uu offset — left and right of enemy
	TArray<FVector> FlankSpots =
	{
		EnemyLoc + RightFlank  * 400.0f,
		EnemyLoc - RightFlank  * 400.0f
	};

	UEnvQueryItemType_Point::SetContextHelper(ContextData, FlankSpots);
	UE_LOG(LogTemp, Verbose, TEXT("EnvQueryContext_CompanionSpot: Providing 2 flank spots at 400uu offset"));
}

void UEnvQueryContext_CompanionSpot::ProvideTrapSpots(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	AActor* Querier = Cast<AActor>(QueryInstance.Owner.Get());
	if (!Querier) { return; }

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(Querier->GetWorld(), 0);
	if (!PlayerPawn) { return; }

	FVector EnemyLoc = Querier->GetActorLocation();
	FVector ToPlayer = (PlayerPawn->GetActorLocation() - EnemyLoc).GetSafeNormal();

	// Projected intercept: 300uu ahead of enemy along movement path
	TArray<FVector> TrapSpots =
	{
		EnemyLoc + ToPlayer * 300.0f,
		EnemyLoc + ToPlayer * 150.0f
	};

	UEnvQueryItemType_Point::SetContextHelper(ContextData, TrapSpots);
	UE_LOG(LogTemp, Verbose, TEXT("EnvQueryContext_CompanionSpot: Providing 2 trap placement intercepts"));
}

void UEnvQueryContext_CompanionSpot::ProvideSanctuaryAnchorSpots(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const
{
	AActor* Querier = Cast<AActor>(QueryInstance.Owner.Get());
	if (!Querier) { return; }

	APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(Querier->GetWorld(), 0);
	if (!PlayerPawn) { return; }

	FVector KaelenLoc = PlayerPawn->GetActorLocation();
	FVector Right = PlayerPawn->GetActorRightVector();
	FVector Forward = PlayerPawn->GetActorForwardVector();

	// Sanctuary anchor: two cover positions flanking Kaelen at 250uu — behind and to the sides
	TArray<FVector> AnchorSpots =
	{
		KaelenLoc - Forward * 250.0f,
		KaelenLoc + Right   * 250.0f,
		KaelenLoc - Right   * 250.0f
	};

	UEnvQueryItemType_Point::SetContextHelper(ContextData, AnchorSpots);
	UE_LOG(LogTemp, Verbose, TEXT("EnvQueryContext_CompanionSpot: Providing 3 sanctuary anchor spots near Kaelen"));
}
