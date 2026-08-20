// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 661: Ashen Glancing Deflection Parry Evaluator

#include "AshenGlancingDeflectionParryEvaluator.h"

int32 UAshenGlancingDeflectionParryEvaluator::EvaluateParryWindowFrames(int32 BaseFrames, bool bIsUnbrokenActive)
{
	const int32 BonusFrames = bIsUnbrokenActive ? 3 : 0;
	ActiveFrameWindow = FMath::Clamp(BaseFrames + BonusFrames, 1, 30);

	OnParryWindowEvaluated.Broadcast(ActiveFrameWindow, bIsUnbrokenActive);

	UE_LOG(LogTemp, Warning, TEXT("UAshenGlancingDeflectionParryEvaluator: PARRY WINDOW EVALUATED -> Base: %d frames | Bonus: +%d frames -> Total Window: %d frames."),
		BaseFrames, BonusFrames, ActiveFrameWindow);

	return ActiveFrameWindow;
}
