// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 243: Ashen Sanctuary Fast Travel UI Controller

#include "AshenSanctuaryFastTravelUIController.h"
#include "AshenFastTravelSubsystem.h"
#include "Engine/World.h"
#include "GameFramework/Pawn.h"

UAshenSanctuaryFastTravelUIController::UAshenSanctuaryFastTravelUIController()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSanctuaryFastTravelUIController::BeginPlay()
{
	Super::BeginPlay();
}

bool UAshenSanctuaryFastTravelUIController::RequestFastTravelToSanctuary(FName DestinationID)
{
	if (!GetWorld() || DestinationID.IsNone()) return false;

	UAshenFastTravelSubsystem* TravelSub = GetWorld()->GetSubsystem<UAshenFastTravelSubsystem>();
	if (!TravelSub) return false;

	AActor* OwnerActor = GetOwner();
	APawn* PlayerPawn = Cast<APawn>(OwnerActor);
	if (!PlayerPawn) return false;

	bool bSuccess = TravelSub->FastTravelToSanctuary(PlayerPawn, DestinationID);
	if (bSuccess)
	{
		OnFastTravelInitiated.Broadcast(DestinationID, PlayerPawn->GetActorLocation());
		UE_LOG(LogTemp, Warning, TEXT("UAshenSanctuaryFastTravelUIController: Fast Travel to '%s' INITIATED!"), *DestinationID.ToString());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenSanctuaryFastTravelUIController: Fast Travel to '%s' FAILED (Not unlocked or invalid)."), *DestinationID.ToString());
	}

	return bSuccess;
}
