// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenCartographicSurveyBeaconActor.generated.h"

/**
 * AAshenCartographicSurveyBeaconActor
 * 3D world vantage point beacon providing full panoramic sector revelation upon interaction.
 */
UCLASS()
class ASHENOATH_API AAshenCartographicSurveyBeaconActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenCartographicSurveyBeaconActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Cartography")
	FName BeaconSectorName = FName(TEXT("Ruined_Spire_Overlook"));

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Cartography")
	bool bHasBeenSurveyed = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Cartography")
	bool ActivateSurveyBeacon();
};
