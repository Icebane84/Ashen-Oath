// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AshenShroudKnightCharacter.generated.h"

UENUM(BlueprintType)
enum class EAshenShroudSpiritState : uint8
{
	Idle,
	Stalking,
	SpectralPhasing,
	WarpStriking,
	ConsecratedStun,
	PinnedByKaelen
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShroudKnightStateChanged, EAshenShroudSpiritState, NewState);

/**
 * AAshenShroudKnightCharacter
 * Tormented malevolent spirit enemy featuring spectral dither-shading,
 * dynamic wall phasing, and target-blind creeping paranoia infection.
 */
UCLASS()
class ASHENOATH_API AAshenShroudKnightCharacter : public ACharacter
{
	GENERATED_BODY()
public:
	AAshenShroudKnightCharacter();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Shroud Knight")
	FOnShroudKnightStateChanged OnShroudKnightStateChanged;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Shroud Knight")
	EAshenShroudSpiritState CurrentState = EAshenShroudSpiritState::Idle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Shroud Knight")
	float ParanoiaAfflictionRate = 0.15f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Shroud Knight")
	void SetShroudKnightState(EAshenShroudSpiritState NewState);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Shroud Knight")
	bool InitiateSpectralPhase();
};
