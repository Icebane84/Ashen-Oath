// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSanctuaryFastTravelUIController.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnFastTravelInitiatedSignature, FName, DestinationID, FVector, DestinationLocation);

/**
 * UAshenSanctuaryFastTravelUIController
 *
 * Controller component bridging UMG map node selection to UAshenFastTravelSubsystem teleportation logic.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanctuaryFastTravelUIController : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanctuaryFastTravelUIController();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|FastTravelUI")
	bool RequestFastTravelToSanctuary(FName DestinationID);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|FastTravelUI|Events")
	FOnFastTravelInitiatedSignature OnFastTravelInitiated;
};
