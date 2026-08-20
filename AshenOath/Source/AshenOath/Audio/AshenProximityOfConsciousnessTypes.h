// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenProximityOfConsciousnessTypes.generated.h"

UENUM(BlueprintType)
enum class EAudioConsciousnessChannel : uint8
{
	WorldSpatial      UMETA(DisplayName = "World Channel (TV / Surround Speakers)"),
	PersonalAction    UMETA(DisplayName = "Personal Action Channel (DualSense Controller Speaker)"),
	InternalSomatic   UMETA(DisplayName = "Internal / Somatic Channel (Headphones / Intimate Mix)")
};

USTRUCT(BlueprintType)
struct FDualSenseVoiceCue
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	FName SpeakerID = NAME_None; // e.g. Garrett, Serafina, KaelenInternal

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	FString SpokenLine = TEXT("");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	EAudioConsciousnessChannel TargetChannel = EAudioConsciousnessChannel::PersonalAction;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	bool bIsActionableTacticalTiming = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float HapticRumbleIntensity = 0.5f; // 0.0 to 1.0
};

USTRUCT(BlueprintType)
struct FActionableAudioPrompt
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	FName PromptID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float ActionWindowDurationSeconds = 1.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	bool bHasVisualAccessibilityFallback = true;
};
