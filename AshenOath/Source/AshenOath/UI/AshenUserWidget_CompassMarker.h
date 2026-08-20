// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "AshenUserWidget_CompassMarker.generated.h"

UENUM(BlueprintType)
enum class EAshenCompassMarkerType : uint8
{
	Sanctuary UMETA(DisplayName = "Sanctuary"),
	QuestGoal UMETA(DisplayName = "Quest Goal"),
	Hostile   UMETA(DisplayName = "Hostile Enemy"),
	CustomPin UMETA(DisplayName = "Custom Pin")
};

/**
 * UAshenUserWidget_CompassMarker
 *
 * UMG backing widget for individual directional markers rendered on the HUD compass bar.
 */
UCLASS()
class ASHENOATH_API UAshenUserWidget_CompassMarker : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void SetupMarker(FName MarkerID, EAshenCompassMarkerType MarkerType, FVector WorldLocation);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|UI")
	void UpdateScreenOffset(float NormalizedOffset, float DistanceMeters);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FName CurrentMarkerID;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	EAshenCompassMarkerType CurrentMarkerType = EAshenCompassMarkerType::Sanctuary;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	FVector CachedWorldLocation = FVector::ZeroVector;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float CurrentNormalizedOffset = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|UI")
	float CurrentDistanceMeters = 0.0f;
};
