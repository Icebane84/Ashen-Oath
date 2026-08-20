// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenAct01DialogueAnnotationBroadcaster.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAct01SubtitleBroadcastedSignature, FName, SpeakerName, FText, DialogueLine);

/**
 * UAshenAct01DialogueAnnotationBroadcaster
 *
 * Subsystem broadcasting Act 01 cinematic subtitles & speaker tags (Where Light Fades Act 01).
 */
UCLASS()
class ASHENOATH_API UAshenAct01DialogueAnnotationBroadcaster : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Act01Dialogue")
	void BroadcastCinematicSubtitle(FName SpeakerName, FText DialogueLine);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Act01Dialogue|Events")
	FOnAct01SubtitleBroadcastedSignature OnSubtitleBroadcasted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Act01Dialogue")
	int32 TotalSubtitlesBroadcasted = 0;
};
