// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulConstellationTypes.h"
#include "AshenLensCompanionTrustAdapter.generated.h"

/**
 * UAshenLensCompanionTrustAdapter
 * Modulates companion trust accumulation rates based on the active philosophical lens (+15% Garrett on Accountability, +15% Serafina on Grace).
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenLensCompanionTrustAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenLensCompanionTrustAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Companions")
	float ModulateTrustDelta(FName CompanionID, float BaseDelta, EInterpretiveLens Lens);
};
