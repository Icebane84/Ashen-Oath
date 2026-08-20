// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenNightmareIncursionAIDirectorComponent.generated.h"

/**
 * UAshenNightmareIncursionAIDirectorComponent
 * AI Director modulating phantom spawn rates, aggression scaling, and reality distortion flanking tactics during incursions.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNightmareIncursionAIDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNightmareIncursionAIDirectorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | AI")
	int32 MaxConcurrentPhantoms = 6;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | AI")
	int32 CalculateDesiredPhantomCount(float IncursionIntensity, int32 ActiveRifts) const;
};
