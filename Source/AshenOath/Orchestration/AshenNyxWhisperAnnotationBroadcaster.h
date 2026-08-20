// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenNyxWhisperAnnotationBroadcaster.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnNyxWhisperBroadcastedSignature, FText, WhisperSubtitleText, float, TemptationLevel);

/**
 * UAshenNyxWhisperAnnotationBroadcaster
 *
 * Subsystem broadcasting Nyx's entropic whisper subtitles & audio tags (UMB-INT-001 Memory Slice).
 */
UCLASS()
class ASHENOATH_API UAshenNyxWhisperAnnotationBroadcaster : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|NyxAnnotations")
	void BroadcastNyxWhisper(FText WhisperText, float TemptationLevel = 50.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|NyxAnnotations|Events")
	FOnNyxWhisperBroadcastedSignature OnNyxWhisperBroadcasted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|NyxAnnotations")
	int32 TotalWhispersBroadcasted = 0;
};
