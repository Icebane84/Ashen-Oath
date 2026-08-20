// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "AshenUnreliableNarratorEnvironmentalVolume.generated.h"

UENUM(BlueprintType)
enum class EAshenEnvironmentalHallucinationState : uint8
{
	Default_Coherent,
	Flickering_Slight,
	Warped_Labyrinth,
	Reality_Collapsed
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEnvironmentalHallucinationChanged, EAshenEnvironmentalHallucinationState, NewState);

/**
 * AAshenUnreliableNarratorEnvironmentalVolume
 * Spatial volume dynamically shifting room geometry, corridor loops, and illusory doorways based on sanity.
 */
UCLASS()
class ASHENOATH_API AAshenUnreliableNarratorEnvironmentalVolume : public AVolume
{
	GENERATED_BODY()
public:
	AAshenUnreliableNarratorEnvironmentalVolume();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Hallucination")
	FOnEnvironmentalHallucinationChanged OnHallucinationChanged;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Hallucination")
	EAshenEnvironmentalHallucinationState CurrentHallucinationState = EAshenEnvironmentalHallucinationState::Default_Coherent;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Hallucination")
	void EvaluateSanityDistortion(float SanityLevel, float DebtLevel);
};
