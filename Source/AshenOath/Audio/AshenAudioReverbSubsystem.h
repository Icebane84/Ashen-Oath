// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenAudioReverbSubsystem.generated.h"

UENUM(BlueprintType)
enum class EAshenReverbPreset : uint8
{
	OpenAir      UMETA(DisplayName = "Open Air"),
	CaveCathedral UMETA(DisplayName = "Cave Cathedral"),
	InteriorRuins UMETA(DisplayName = "Interior Ruins"),
	MindscapeAbyss UMETA(DisplayName = "Mindscape Abyss")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnReverbPresetChangedSignature, EAshenReverbPreset, NewPreset);

/**
 * UAshenAudioReverbSubsystem
 *
 * World Subsystem managing spatial audio reverb environment presets across Frozen Tarn & Mindscape levels.
 */
UCLASS()
class ASHENOATH_API UAshenAudioReverbSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Audio")
	void SetReverbPreset(EAshenReverbPreset Preset);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Audio")
	EAshenReverbPreset GetCurrentPreset() const { return CurrentPreset; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Audio|Events")
	FOnReverbPresetChangedSignature OnReverbPresetChanged;

private:
	EAshenReverbPreset CurrentPreset = EAshenReverbPreset::OpenAir;
};
