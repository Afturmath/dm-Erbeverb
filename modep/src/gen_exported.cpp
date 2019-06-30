#include "gen_exported.h"

namespace gen_exported {

/*******************************************************************************************************************
Cycling '74 License for Max-Generated Code for Export
Copyright (c) 2016 Cycling '74
The code that Max generates automatically and that end users are capable of exporting and using, and any
  associated documentation files (the “Software”) is a work of authorship for which Cycling '74 is the author
  and owner for copyright purposes.  A license is hereby granted, free of charge, to any person obtaining a
  copy of the Software (“Licensee”) to use, copy, modify, merge, publish, and distribute copies of the Software,
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The Software is licensed to Licensee only for non-commercial use. Users who wish to make commercial use of the
  Software must contact the copyright owner to determine if a license for commercial use is available, and the
  terms and conditions for same, which may include fees or royalties. For commercial use, please send inquiries
  to licensing (at) cycling74.com.  The determination of whether a use is commercial use or non-commercial use is based
  upon the use, not the user. The Software may be used by individuals, institutions, governments, corporations, or
  other business whether for-profit or non-profit so long as the use itself is not a commercialization of the
  materials or a use that generates or is intended to generate income, revenue, sales or profit.
The above copyright notice and this license shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*******************************************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Delay m_allpass_94;
	Delay m_delay_13;
	Delay m_delay_12;
	Delay m_delay_11;
	Delay m_allpass_104;
	Delay m_predelayLR_14;
	Delay m_allpass_100;
	Delay m_allpass_102;
	Delay m_allpass_96;
	Delay m_allpass_98;
	Delay m_allpass_106;
	Delay m_delay_10;
	Delay m_allpass_120;
	Delay m_allpass_118;
	Delay m_allpass_108;
	Delay m_allpass_122;
	Delay m_allpass_124;
	Delay m_allpass_116;
	Delay m_allpass_112;
	Delay m_allpass_114;
	Delay m_allpass_110;
	Delta __m_delta_39;
	Delta __m_delta_38;
	Delta __m_delta_40;
	Delta __m_delta_37;
	Delta __m_delta_62;
	Delta __m_delta_65;
	Delta __m_delta_60;
	Delta __m_delta_67;
	Phasor __m_phasor_63;
	Phasor __m_phasor_36;
	Phasor __m_phasor_30;
	Phasor __m_phasor_31;
	Phasor __m_phasor_58;
	Sah __m_sah_51;
	Sah __m_sah_53;
	Sah __m_sah_49;
	Sah __m_sah_52;
	Sah __m_sah_48;
	Sah __m_sah_56;
	Sah __m_sah_54;
	Sah __m_sah_55;
	Sah __m_sah_59;
	Sah __m_sah_47;
	Sah __m_sah_50;
	Sah __m_sah_45;
	Sah __m_sah_66;
	Sah __m_sah_46;
	Sah __m_sah_64;
	Sah __m_sah_41;
	Sah __m_sah_43;
	Sah __m_sah_42;
	Sah __m_sah_44;
	Sah __m_sah_61;
	SineCycle __m_cycle_34;
	SineCycle __m_cycle_33;
	SineCycle __m_cycle_35;
	SineCycle __m_cycle_32;
	SineData __sinedata;
	int __exception;
	int vectorsize;
	t_sample m_absorb_3;
	t_sample m_decay_2;
	t_sample samples_to_seconds;
	t_sample m_tilt_4;
	t_sample m_depth_6;
	t_sample m_predelay_5;
	t_sample m_speed_7;
	t_sample m_mix_1;
	t_sample samplerate;
	t_sample m_z2R_125;
	t_sample m_z2R_132;
	t_sample m_z1R_133;
	t_sample m_size_8;
	t_sample m_z1L_128;
	t_sample m_z1R_126;
	t_sample m_z2L_127;
	t_sample m_z2L_134;
	t_sample m_reverse_9;
	t_sample m_lowpass_17;
	t_sample m_lowpass_71;
	t_sample m_lowpass_75;
	t_sample m_lowpass_79;
	t_sample m_lowpass_25;
	t_sample m_lowpass_29;
	t_sample m_lowpass_27;
	t_sample m_lowpass_15;
	t_sample m_lowpass_83;
	t_sample m_lowpass_88;
	t_sample m_lowpass_21;
	t_sample m_lowpass_19;
	t_sample m_lowpass_86;
	t_sample m_lowpass_23;
	t_sample m_lowpass_90;
	t_sample m_lowpass_92;
	t_sample m_z1L_135;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_mix_1 = 50;
		m_decay_2 = 85;
		m_absorb_3 = 30;
		m_tilt_4 = 0;
		m_predelay_5 = 7;
		m_depth_6 = 0;
		m_speed_7 = 1;
		m_size_8 = 40;
		m_reverse_9 = 0;
		m_delay_10.reset("m_delay_10", ((int)141176));
		m_delay_11.reset("m_delay_11", ((int)119001));
		m_delay_12.reset("m_delay_12", ((int)101519));
		m_delay_13.reset("m_delay_13", ((int)88320));
		m_predelayLR_14.reset("m_predelayLR_14", ((int)48336));
		m_lowpass_15 = ((int)0);
		m_lowpass_17 = ((int)0);
		m_lowpass_19 = ((int)0);
		m_lowpass_21 = ((int)0);
		m_lowpass_23 = ((int)0);
		m_lowpass_25 = ((int)0);
		m_lowpass_27 = ((int)0);
		m_lowpass_29 = ((int)0);
		samples_to_seconds = (1 / samplerate);
		__m_phasor_30.reset(0);
		__m_phasor_31.reset(0);
		__m_cycle_32.reset(samplerate, 0);
		__m_cycle_33.reset(samplerate, 0);
		__m_cycle_34.reset(samplerate, 0);
		__m_cycle_35.reset(samplerate, 0);
		__m_phasor_36.reset(0);
		__m_delta_37.reset(0);
		__m_delta_38.reset(0);
		__m_delta_39.reset(0);
		__m_delta_40.reset(0);
		__m_sah_41.reset(0);
		__m_sah_42.reset(0);
		__m_sah_43.reset(0);
		__m_sah_44.reset(0);
		__m_sah_45.reset(0);
		__m_sah_46.reset(0);
		__m_sah_47.reset(0);
		__m_sah_48.reset(0);
		__m_sah_49.reset(0);
		__m_sah_50.reset(0);
		__m_sah_51.reset(0);
		__m_sah_52.reset(0);
		__m_sah_53.reset(0);
		__m_sah_54.reset(0);
		__m_sah_55.reset(0);
		__m_sah_56.reset(0);
		__m_phasor_58.reset(0);
		__m_sah_59.reset(0);
		__m_delta_60.reset(0);
		__m_sah_61.reset(0);
		__m_delta_62.reset(0);
		__m_phasor_63.reset(0);
		__m_sah_64.reset(0);
		__m_delta_65.reset(0);
		__m_sah_66.reset(0);
		__m_delta_67.reset(0);
		m_lowpass_71 = ((int)0);
		m_lowpass_75 = ((int)0);
		m_lowpass_79 = ((int)0);
		m_lowpass_83 = ((int)0);
		m_lowpass_86 = ((int)0);
		m_lowpass_88 = ((int)0);
		m_lowpass_90 = ((int)0);
		m_lowpass_92 = ((int)0);
		m_allpass_94.reset("m_allpass_94", ((int)1440));
		m_allpass_96.reset("m_allpass_96", ((int)1440));
		m_allpass_98.reset("m_allpass_98", ((int)1440));
		m_allpass_100.reset("m_allpass_100", ((int)1440));
		m_allpass_102.reset("m_allpass_102", ((int)1440));
		m_allpass_104.reset("m_allpass_104", ((int)1440));
		m_allpass_106.reset("m_allpass_106", ((int)1440));
		m_allpass_108.reset("m_allpass_108", ((int)1440));
		m_allpass_110.reset("m_allpass_110", ((int)1440));
		m_allpass_112.reset("m_allpass_112", ((int)1440));
		m_allpass_114.reset("m_allpass_114", ((int)1440));
		m_allpass_116.reset("m_allpass_116", ((int)1440));
		m_allpass_118.reset("m_allpass_118", ((int)1440));
		m_allpass_120.reset("m_allpass_120", ((int)1440));
		m_allpass_122.reset("m_allpass_122", ((int)1440));
		m_allpass_124.reset("m_allpass_124", ((int)1440));
		m_z2R_125 = ((int)0);
		m_z1R_126 = ((int)0);
		m_z2L_127 = ((int)0);
		m_z1L_128 = ((int)0);
		m_z2R_132 = ((int)0);
		m_z1R_133 = ((int)0);
		m_z2L_134 = ((int)0);
		m_z1L_135 = ((int)0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__out1 == 0) || (__out2 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		samples_to_seconds = (1 / samplerate);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			t_sample reverseLP = lowpass_d_d(m_reverse_9, ((t_sample)0.997243));
			t_sample sizeLP = lowpass_d_d_16(((m_size_8 * samplerate) * ((t_sample)0.0029411764705882)), ((t_sample)0.9997243));
			t_sample depthLP = lowpass_d_d_18((m_depth_6 * ((t_sample)0.01)), ((t_sample)0.9997243));
			t_sample predelayLP = lowpass_d_d_20(m_predelay_5, ((t_sample)0.997243));
			t_sample tiltLP = lowpass_d_d_22(((m_tilt_4 * ((t_sample)0.005)) + ((t_sample)0.5)), ((t_sample)0.9997243));
			t_sample absorbLP = lowpass_d_d_24((m_absorb_3 * ((t_sample)0.01)), ((t_sample)0.9997243));
			t_sample decayLP = lowpass_d_d_26((m_decay_2 * ((t_sample)0.005)), ((t_sample)0.9997243));
			t_sample mixLP = lowpass_d_d_28((m_mix_1 * ((t_sample)0.01)), ((t_sample)0.9997243));
			m_predelayLR_14.write(in1);
			int revflag = (reverseLP > ((t_sample)1e-05));
			t_sample predelayLP_samps = (predelayLP * (samplerate * 0.001));
			t_sample predelay1 = m_predelayLR_14.read_linear(predelayLP_samps);
			t_sample predelay2 = ((int)0);
			t_sample predelay3 = ((int)0);
			if (revflag) {
				t_sample revphasor = __m_phasor_30(safediv(((int)1000), predelayLP), samples_to_seconds);
				t_sample revphasorA = (revphasor * ((int)2));
				t_sample revphasorB = (safemod((revphasor + ((t_sample)0.5)), ((int)1)) * ((int)2));
				t_sample pretimeA = (revphasorA * predelayLP_samps);
				t_sample pretimeB = (revphasorB * predelayLP_samps);
				t_sample xfadeFac = (predelayLP * ((t_sample)0.28571428571429));
				t_sample xfadeOff = (safediv(((int)1), xfadeFac) + ((int)1));
				t_sample xfadeA1 = (revphasorA * xfadeFac);
				t_sample xfadeA_138 = ((xfadeA1 <= ((int)0)) ? ((int)0) : ((xfadeA1 >= ((int)1)) ? ((int)1) : xfadeA1));
				t_sample xfadeA2 = ((xfadeOff - revphasorA) * xfadeFac);
				t_sample xfadeA_139 = ((xfadeA2 <= ((int)0)) ? ((int)0) : ((xfadeA2 >= ((int)1)) ? ((int)1) : xfadeA2));
				t_sample xfadeA = (xfadeA_138 * xfadeA_139);
				t_sample xfadeB = (((int)1) - xfadeA);
				predelay2 = (m_predelayLR_14.read_linear(pretimeA) * xfadeA);
				predelay3 = (m_predelayLR_14.read_linear(pretimeB) * xfadeB);
				
			};
			t_sample add_153 = (predelay2 + predelay3);
			t_sample mix_152 = (predelay1 + (reverseLP * (add_153 - predelay1)));
			t_sample early1 = m_delay_13.read_step(((int)0));
			t_sample early2 = m_delay_13.read_linear((((t_sample)0.207771) * sizeLP));
			t_sample early3 = m_delay_12.read_linear((((t_sample)0.357573) * sizeLP));
			t_sample early4 = m_delay_11.read_step(((int)0));
			t_sample early5 = m_delay_11.read_linear((((t_sample)0.421567) * sizeLP));
			t_sample early6 = m_delay_10.read_step(((int)0));
			t_sample early7 = m_delay_10.read_linear((((t_sample)0.501143) * sizeLP));
			t_sample delayt1 = (((t_sample)0.625597) * sizeLP);
			t_sample delayt2 = (((t_sample)0.719094) * sizeLP);
			t_sample delayt3 = (((t_sample)0.842925) * sizeLP);
			t_sample moddepth = ((depthLP * depthLP) * ((int)480));
			t_sample FDN1 = ((int)0);
			t_sample FDN2 = ((int)0);
			t_sample FDN3 = ((int)0);
			t_sample FDN4 = ((int)0);
			t_sample FDN1mod = ((int)0);
			t_sample FDN2mod = ((int)0);
			t_sample FDN3mod = ((int)0);
			t_sample FDN4mod = ((int)0);
			if ((depthLP <= ((int)0))) {
				t_sample master = __m_phasor_31(m_speed_7, samples_to_seconds);
				__m_cycle_32.phase(safemod((master + ((t_sample)0.23)), ((int)1)));
				t_sample cycle_130 = __m_cycle_32(__sinedata);
				t_sample cycle_131 = __m_cycle_32.phase();
				t_sample mod1 = (((cycle_130 + ((int)1)) * moddepth) * ((t_sample)0.5));
				__m_cycle_33.phase(safemod((master + ((t_sample)0.541)), ((int)1)));
				t_sample cycle_132 = __m_cycle_33(__sinedata);
				t_sample cycle_133 = __m_cycle_33.phase();
				t_sample mod2 = (((cycle_132 + ((int)1)) * moddepth) * ((t_sample)0.5));
				__m_cycle_34.phase(safemod((master + ((t_sample)0.0321)), ((int)1)));
				t_sample cycle_134 = __m_cycle_34(__sinedata);
				t_sample cycle_135 = __m_cycle_34.phase();
				t_sample mod3 = (((cycle_134 + ((int)1)) * moddepth) * ((t_sample)0.5));
				__m_cycle_35.phase(safemod((master + ((t_sample)0.87102)), ((int)1)));
				t_sample cycle_136 = __m_cycle_35(__sinedata);
				t_sample cycle_137 = __m_cycle_35.phase();
				t_sample mod4 = (((cycle_136 + ((int)1)) * moddepth) * ((t_sample)0.5));
				FDN1 = m_delay_13.read_linear((delayt1 + mod1));
				FDN2 = m_delay_12.read_linear((delayt2 + mod2));
				FDN3 = m_delay_11.read_linear((delayt3 + mod3));
				FDN4 = m_delay_10.read_linear((sizeLP + mod4));
				FDN1mod = FDN1;
				FDN2mod = FDN2;
				FDN3mod = FDN3;
				FDN4mod = FDN4;
				
			} else {
				t_sample random1 = ((noise() * ((t_sample)0.5)) + ((t_sample)0.5));
				t_sample random2 = ((noise() * ((t_sample)0.5)) + ((t_sample)0.5));
				t_sample random3 = ((noise() * ((t_sample)0.5)) + ((t_sample)0.5));
				t_sample random4 = ((noise() * ((t_sample)0.5)) + ((t_sample)0.5));
				t_sample phasor1 = __m_phasor_36((m_speed_7 * ((t_sample)0.25)), samples_to_seconds);
				t_sample phasor2 = safemod((phasor1 + ((t_sample)0.25)), ((int)1));
				t_sample phasor3 = safemod((phasor1 + ((t_sample)0.5)), ((int)1));
				t_sample phasor4 = safemod((phasor1 + ((t_sample)0.75)), ((int)1));
				t_sample window1 = sin((phasor1 * ((t_sample)3.1415926535898)));
				t_sample window_140 = (window1 * window1);
				t_sample window2 = sin((phasor2 * ((t_sample)3.1415926535898)));
				t_sample window_141 = (window2 * window2);
				t_sample window3 = (((int)1) - window_140);
				t_sample window4 = (((int)1) - window_141);
				t_sample trig1 = __m_delta_37(phasor1);
				t_sample trig2 = __m_delta_38(phasor2);
				t_sample trig3 = __m_delta_39(phasor3);
				t_sample trig4 = __m_delta_40(phasor4);
				t_sample randt01 = (__m_sah_41(random1, trig1, ((int)0)) * moddepth);
				t_sample randt02 = (__m_sah_42(random1, trig2, ((int)0)) * moddepth);
				t_sample randt03 = (__m_sah_43(random1, trig3, ((int)0)) * moddepth);
				t_sample randt04 = (__m_sah_44(random1, trig4, ((int)0)) * moddepth);
				t_sample randt05 = (__m_sah_45(random2, trig1, ((int)0)) * moddepth);
				t_sample randt06 = (__m_sah_46(random2, trig2, ((int)0)) * moddepth);
				t_sample randt07 = (__m_sah_47(random2, trig3, ((int)0)) * moddepth);
				t_sample randt08 = (__m_sah_48(random2, trig4, ((int)0)) * moddepth);
				t_sample randt09 = (__m_sah_49(random3, trig1, ((int)0)) * moddepth);
				t_sample randt10 = (__m_sah_50(random3, trig2, ((int)0)) * moddepth);
				t_sample randt11 = (__m_sah_51(random3, trig3, ((int)0)) * moddepth);
				t_sample randt12 = (__m_sah_52(random3, trig4, ((int)0)) * moddepth);
				t_sample randt13 = (__m_sah_53(random4, trig1, ((int)0)) * moddepth);
				t_sample randt14 = (__m_sah_54(random4, trig2, ((int)0)) * moddepth);
				t_sample randt15 = (__m_sah_55(random4, trig3, ((int)0)) * moddepth);
				t_sample randt16 = (__m_sah_56(random4, trig4, ((int)0)) * moddepth);
				FDN1mod = (FDN1mod + (m_delay_13.read_linear((delayt1 + randt01)) * window_140));
				FDN1mod = (FDN1mod + (m_delay_13.read_linear((delayt1 + randt02)) * window_141));
				FDN1mod = (FDN1mod + (m_delay_13.read_linear((delayt1 + randt03)) * window3));
				FDN1mod = (FDN1mod + (m_delay_13.read_linear((delayt1 + randt04)) * window4));
				FDN2mod = (FDN2mod + (m_delay_12.read_linear((delayt2 + randt05)) * window_140));
				FDN2mod = (FDN2mod + (m_delay_12.read_linear((delayt2 + randt06)) * window_141));
				FDN2mod = (FDN2mod + (m_delay_12.read_linear((delayt2 + randt07)) * window3));
				FDN2mod = (FDN2mod + (m_delay_12.read_linear((delayt2 + randt08)) * window4));
				FDN3mod = (FDN3mod + (m_delay_11.read_linear((delayt3 + randt09)) * window_140));
				FDN3mod = (FDN3mod + (m_delay_11.read_linear((delayt3 + randt10)) * window_141));
				FDN3mod = (FDN3mod + (m_delay_11.read_linear((delayt3 + randt11)) * window3));
				FDN3mod = (FDN3mod + (m_delay_11.read_linear((delayt3 + randt12)) * window4));
				FDN4mod = (FDN4mod + (m_delay_10.read_linear((sizeLP + randt13)) * window_140));
				FDN4mod = (FDN4mod + (m_delay_10.read_linear((sizeLP + randt14)) * window_141));
				FDN4mod = (FDN4mod + (m_delay_10.read_linear((sizeLP + randt15)) * window3));
				FDN4mod = (FDN4mod + (m_delay_10.read_linear((sizeLP + randt16)) * window4));
				FDN1mod = (FDN1mod * ((t_sample)0.5));
				FDN2mod = (FDN2mod * ((t_sample)0.5));
				FDN3mod = (FDN3mod * ((t_sample)0.5));
				FDN4mod = (FDN4mod * ((t_sample)0.5));
				t_sample maxa_57 = (((int)5) * (depthLP - ((t_sample)0.8)));
				t_sample shimmer = ((maxa_57 < ((int)0)) ? ((int)0) : maxa_57);
				t_sample shimmerOut1 = ((int)0);
				t_sample shimmerOut2 = ((int)0);
				if (shimmer) {
					t_sample shRandom = ((noise() * ((int)80)) + ((int)80));
					t_sample shPhasor1 = __m_phasor_58(safediv((-samplerate), delayt1), samples_to_seconds);
					t_sample shPhasor2 = safemod((shPhasor1 + ((t_sample)0.5)), ((int)1));
					t_sample shWindow1 = sin((shPhasor1 * ((t_sample)3.1415926535898)));
					t_sample shWindow_142 = (shWindow1 * shWindow1);
					t_sample shWindow2 = (((int)1) - shWindow_142);
					t_sample shRand1 = __m_sah_59(shRandom, __m_delta_60(shPhasor1), ((int)0));
					t_sample shRand2 = __m_sah_61(shRandom, __m_delta_62(shPhasor2), ((int)0));
					t_sample shPhasor3 = __m_phasor_63(safediv((-samplerate), delayt2), samples_to_seconds);
					t_sample shPhasor4 = safemod((shPhasor3 + ((t_sample)0.5)), ((int)1));
					t_sample shWindow3 = sin((shPhasor3 * ((t_sample)3.1415926535898)));
					t_sample shWindow_143 = (shWindow3 * shWindow3);
					t_sample shWindow4 = (((int)1) - shWindow_143);
					t_sample shRand3 = __m_sah_64(shRandom, __m_delta_65(shPhasor3), ((int)0));
					t_sample shRand4 = __m_sah_66(shRandom, __m_delta_67(shPhasor4), ((int)0));
					shimmerOut1 = (m_delay_13.read_linear(((shPhasor1 * delayt1) + shRand1)) * shWindow_142);
					shimmerOut1 = (shimmerOut1 + (m_delay_13.read_linear(((shPhasor2 * delayt1) + shRand2)) * shWindow2));
					shimmerOut2 = (m_delay_12.read_linear(((shPhasor3 * delayt2) + shRand3)) * shWindow_143);
					shimmerOut2 = (shimmerOut2 + (m_delay_12.read_linear(((shPhasor4 * delayt2) + shRand4)) * shWindow4));
					
				};
				t_sample read_155 = m_delay_13.read_linear(delayt1);
				t_sample mix_154 = (read_155 + (shimmer * (shimmerOut1 - read_155)));
				FDN1 = mix_154;
				t_sample read_157 = m_delay_12.read_linear(delayt2);
				t_sample mix_156 = (read_157 + (shimmer * (shimmerOut2 - read_157)));
				FDN2 = mix_156;
				FDN3 = m_delay_11.read_linear(delayt3);
				FDN4 = m_delay_10.read_linear(sizeLP);
				
			};
			t_sample v_68 = ((decayLP - ((t_sample)0.495)) * ((int)200));
			t_sample drive = ((v_68 <= ((int)0)) ? ((int)0) : ((v_68 >= ((int)1)) ? ((int)1) : v_68));
			if (drive) {
				FDN1 = saturate_d_d(FDN1, drive);
				FDN2 = saturate_d_d_72(FDN2, drive);
				FDN3 = saturate_d_d_76(FDN3, drive);
				FDN4 = saturate_d_d_80(FDN4, drive);
				
			};
			t_sample feedback1 = (decayLP * (((FDN1 - FDN2) - FDN3) + FDN4));
			t_sample feedback2 = (decayLP * (((FDN1 + FDN2) - FDN3) - FDN4));
			t_sample feedback3 = (decayLP * (((FDN1 - FDN2) + FDN3) - FDN4));
			t_sample feedback4 = (decayLP * (((FDN1 + FDN2) + FDN3) + FDN4));
			t_sample maxa_84 = ((absorbLP - ((t_sample)0.3)) * ((t_sample)1.428571));
			t_sample damping = ((maxa_84 < ((int)0)) ? ((int)0) : maxa_84);
			t_sample damping1 = lowpass_d_d_85((mix_152 + feedback1), damping);
			t_sample damping2 = lowpass_d_d_87((mix_152 + feedback3), damping);
			t_sample damping3 = lowpass_d_d_89(feedback2, damping);
			t_sample damping4 = lowpass_d_d_91(feedback4, damping);
			t_sample mina_93 = (absorbLP * ((t_sample)2.666667));
			t_sample diff = ((((t_sample)0.8) < mina_93) ? ((t_sample)0.8) : mina_93);
			t_sample diffuse1 = allpass_d_d_d(allpass_d_d_d_95(allpass_d_d_d_97(allpass_d_d_d_99(damping1, ((t_sample)5.020833), diff), ((t_sample)1.854167), diff), ((t_sample)7.229167), diff), ((t_sample)14.604167), diff);
			t_sample diffuse2 = allpass_d_d_d_101(allpass_d_d_d_103(allpass_d_d_d_105(allpass_d_d_d_107(damping2, ((t_sample)4.145833), diff), ((t_sample)3.145833), diff), ((t_sample)7.979167), diff), ((t_sample)13.145833), diff);
			t_sample diffuse3 = allpass_d_d_d_109(allpass_d_d_d_111(allpass_d_d_d_113(allpass_d_d_d_115(damping3, ((t_sample)5.229167), diff), ((t_sample)2.645833), diff), ((t_sample)10.395833), diff), ((t_sample)12.770833), diff);
			t_sample diffuse4 = allpass_d_d_d_117(allpass_d_d_d_119(allpass_d_d_d_121(allpass_d_d_d_123(damping4, ((t_sample)4.395833), diff), ((t_sample)3.770833), diff), ((t_sample)5.854167), diff), ((t_sample)14.020833), diff);
			m_delay_13.write(diffuse1);
			m_delay_12.write(diffuse2);
			m_delay_11.write(diffuse3);
			m_delay_10.write(diffuse4);
			t_sample earlyRefl = (((t_sample)0.15) * ((((((early1 + early2) + early3) + early4) + early5) + early6) + early7));
			t_sample reverbL = (((((FDN1mod * ((t_sample)0.75)) + (FDN2mod * ((t_sample)0.25))) + (FDN3mod * ((t_sample)0.5))) + (FDN4mod * ((t_sample)0.5))) + earlyRefl);
			t_sample reverbR = (((((FDN1mod * ((t_sample)0.25)) + (FDN2mod * ((t_sample)0.75))) + (FDN3mod * ((t_sample)0.5))) + (FDN4mod * ((t_sample)0.5))) + earlyRefl);
			t_sample gainlow = dbtoa(((tiltLP * ((int)-24)) + ((int)12)));
			t_sample gainhigh = dbtoa(((tiltLP * ((int)48)) - ((int)24)));
			t_sample return_129;
			t_sample return_130;
			biquad_d_d_i_d_d_i(reverbL, reverbR, ((int)300), gainlow, ((t_sample)0.8), ((int)0), return_129, return_130);
			t_sample tiltlowL = return_129;
			t_sample tiltlowR = return_130;
			t_sample return_136;
			t_sample return_137;
			biquad_d_d_i_d_d_i_131(tiltlowL, tiltlowR, ((int)6000), gainhigh, ((t_sample)0.8), ((int)1), return_136, return_137);
			t_sample tiltoutL = return_136;
			t_sample tiltoutR = return_137;
			t_sample outputL = cosine_interp(mixLP, in1, tiltoutL);
			t_sample outputR = cosine_interp(mixLP, in1, tiltoutR);
			t_sample out1 = outputL;
			t_sample out2 = outputR;
			m_delay_10.step();
			m_delay_11.step();
			m_delay_12.step();
			m_delay_13.step();
			m_predelayLR_14.step();
			m_allpass_94.step();
			m_allpass_96.step();
			m_allpass_98.step();
			m_allpass_100.step();
			m_allpass_102.step();
			m_allpass_104.step();
			m_allpass_106.step();
			m_allpass_108.step();
			m_allpass_110.step();
			m_allpass_112.step();
			m_allpass_114.step();
			m_allpass_116.step();
			m_allpass_118.step();
			m_allpass_120.step();
			m_allpass_122.step();
			m_allpass_124.step();
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			
		};
		return __exception;
		
	};
	inline void set_mix(t_param _value) {
		m_mix_1 = (_value < 0 ? 0 : (_value > 100 ? 100 : _value));
	};
	inline void set_decay(t_param _value) {
		m_decay_2 = (_value < 0 ? 0 : (_value > 120 ? 120 : _value));
	};
	inline void set_absorb(t_param _value) {
		m_absorb_3 = (_value < 0 ? 0 : (_value > 100 ? 100 : _value));
	};
	inline void set_tilt(t_param _value) {
		m_tilt_4 = (_value < -100 ? -100 : (_value > 100 ? 100 : _value));
	};
	inline void set_predelay(t_param _value) {
		m_predelay_5 = (_value < 7 ? 7 : (_value > 500 ? 500 : _value));
	};
	inline void set_depth(t_param _value) {
		m_depth_6 = (_value < -100 ? -100 : (_value > 100 ? 100 : _value));
	};
	inline void set_speed(t_param _value) {
		m_speed_7 = (_value < 0.1 ? 0.1 : (_value > 256 ? 256 : _value));
	};
	inline void set_size(t_param _value) {
		m_size_8 = (_value < 1 ? 1 : (_value > 500 ? 500 : _value));
	};
	inline void set_reverse(t_param _value) {
		m_reverse_9 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline t_sample lowpass_d_d(t_sample input, t_sample coeff) {
		t_sample mix_151 = (input + (coeff * (m_lowpass_15 - input)));
		m_lowpass_15 = mix_151;
		return m_lowpass_15;
		
	};
	inline t_sample lowpass_d_d_16(t_sample input, t_sample coeff) {
		t_sample mix_151 = (input + (coeff * (m_lowpass_17 - input)));
		m_lowpass_17 = mix_151;
		return m_lowpass_17;
		
	};
	inline t_sample lowpass_d_d_18(t_sample input, t_sample coeff) {
		t_sample mix_151 = (input + (coeff * (m_lowpass_19 - input)));
		m_lowpass_19 = mix_151;
		return m_lowpass_19;
		
	};
	inline t_sample lowpass_d_d_20(t_sample input, t_sample coeff) {
		t_sample mix_151 = (input + (coeff * (m_lowpass_21 - input)));
		m_lowpass_21 = mix_151;
		return m_lowpass_21;
		
	};
	inline t_sample lowpass_d_d_22(t_sample input, t_sample coeff) {
		t_sample mix_151 = (input + (coeff * (m_lowpass_23 - input)));
		m_lowpass_23 = mix_151;
		return m_lowpass_23;
		
	};
	inline t_sample lowpass_d_d_24(t_sample input, t_sample coeff) {
		t_sample mix_151 = (input + (coeff * (m_lowpass_25 - input)));
		m_lowpass_25 = mix_151;
		return m_lowpass_25;
		
	};
	inline t_sample lowpass_d_d_26(t_sample input, t_sample coeff) {
		t_sample mix_151 = (input + (coeff * (m_lowpass_27 - input)));
		m_lowpass_27 = mix_151;
		return m_lowpass_27;
		
	};
	inline t_sample lowpass_d_d_28(t_sample input, t_sample coeff) {
		t_sample mix_151 = (input + (coeff * (m_lowpass_29 - input)));
		m_lowpass_29 = mix_151;
		return m_lowpass_29;
		
	};
	inline t_sample saturate_d_d(t_sample input, t_sample drive) {
		int min_69 = (-((int)1));
		t_sample x = ((input <= min_69) ? min_69 : ((input >= ((int)1)) ? ((int)1) : input));
		t_sample cheby = ((((int)4) * safepow(x, ((int)3))) - (((int)3) * x));
		t_sample saturation = ((input - (cheby * ((t_sample)0.05))) * ((t_sample)0.877193));
		t_sample saturation_144 = (saturation - lowpass_d_d_70(saturation, ((t_sample)0.99)));
		t_sample mix_158 = (input + (drive * (saturation_144 - input)));
		return mix_158;
		
	};
	inline t_sample lowpass_d_d_70(t_sample input, t_sample coeff) {
		t_sample mix_151 = (input + (coeff * (m_lowpass_71 - input)));
		m_lowpass_71 = mix_151;
		return m_lowpass_71;
		
	};
	inline t_sample saturate_d_d_72(t_sample input, t_sample drive) {
		int min_73 = (-((int)1));
		t_sample x = ((input <= min_73) ? min_73 : ((input >= ((int)1)) ? ((int)1) : input));
		t_sample cheby = ((((int)4) * safepow(x, ((int)3))) - (((int)3) * x));
		t_sample saturation = ((input - (cheby * ((t_sample)0.05))) * ((t_sample)0.877193));
		t_sample saturation_144 = (saturation - lowpass_d_d_74(saturation, ((t_sample)0.99)));
		t_sample mix_158 = (input + (drive * (saturation_144 - input)));
		return mix_158;
		
	};
	inline t_sample lowpass_d_d_74(t_sample input, t_sample coeff) {
		t_sample mix_151 = (input + (coeff * (m_lowpass_75 - input)));
		m_lowpass_75 = mix_151;
		return m_lowpass_75;
		
	};
	inline t_sample saturate_d_d_76(t_sample input, t_sample drive) {
		int min_77 = (-((int)1));
		t_sample x = ((input <= min_77) ? min_77 : ((input >= ((int)1)) ? ((int)1) : input));
		t_sample cheby = ((((int)4) * safepow(x, ((int)3))) - (((int)3) * x));
		t_sample saturation = ((input - (cheby * ((t_sample)0.05))) * ((t_sample)0.877193));
		t_sample saturation_144 = (saturation - lowpass_d_d_78(saturation, ((t_sample)0.99)));
		t_sample mix_158 = (input + (drive * (saturation_144 - input)));
		return mix_158;
		
	};
	inline t_sample lowpass_d_d_78(t_sample input, t_sample coeff) {
		t_sample mix_151 = (input + (coeff * (m_lowpass_79 - input)));
		m_lowpass_79 = mix_151;
		return m_lowpass_79;
		
	};
	inline t_sample saturate_d_d_80(t_sample input, t_sample drive) {
		int min_81 = (-((int)1));
		t_sample x = ((input <= min_81) ? min_81 : ((input >= ((int)1)) ? ((int)1) : input));
		t_sample cheby = ((((int)4) * safepow(x, ((int)3))) - (((int)3) * x));
		t_sample saturation = ((input - (cheby * ((t_sample)0.05))) * ((t_sample)0.877193));
		t_sample saturation_144 = (saturation - lowpass_d_d_82(saturation, ((t_sample)0.99)));
		t_sample mix_158 = (input + (drive * (saturation_144 - input)));
		return mix_158;
		
	};
	inline t_sample lowpass_d_d_82(t_sample input, t_sample coeff) {
		t_sample mix_151 = (input + (coeff * (m_lowpass_83 - input)));
		m_lowpass_83 = mix_151;
		return m_lowpass_83;
		
	};
	inline t_sample lowpass_d_d_85(t_sample input, t_sample coeff) {
		t_sample mix_151 = (input + (coeff * (m_lowpass_86 - input)));
		m_lowpass_86 = mix_151;
		return m_lowpass_86;
		
	};
	inline t_sample lowpass_d_d_87(t_sample input, t_sample coeff) {
		t_sample mix_151 = (input + (coeff * (m_lowpass_88 - input)));
		m_lowpass_88 = mix_151;
		return m_lowpass_88;
		
	};
	inline t_sample lowpass_d_d_89(t_sample input, t_sample coeff) {
		t_sample mix_151 = (input + (coeff * (m_lowpass_90 - input)));
		m_lowpass_90 = mix_151;
		return m_lowpass_90;
		
	};
	inline t_sample lowpass_d_d_91(t_sample input, t_sample coeff) {
		t_sample mix_151 = (input + (coeff * (m_lowpass_92 - input)));
		m_lowpass_92 = mix_151;
		return m_lowpass_92;
		
	};
	inline t_sample allpass_d_d_d(t_sample input, t_sample time, t_sample gain) {
		t_sample allpassread = m_allpass_94.read_linear((time * (samplerate * 0.001)));
		t_sample feedback = ((allpassread * gain) * ((t_sample)0.5));
		t_sample allpassinput = (input + feedback);
		t_sample feedforward = ((allpassinput * gain) * (-((t_sample)0.5)));
		t_sample allpassoutput = (allpassread + feedforward);
		m_allpass_94.write(allpassinput);
		return allpassoutput;
		
	};
	inline t_sample allpass_d_d_d_95(t_sample input, t_sample time, t_sample gain) {
		t_sample allpassread = m_allpass_96.read_linear((time * (samplerate * 0.001)));
		t_sample feedback = ((allpassread * gain) * ((t_sample)0.5));
		t_sample allpassinput = (input + feedback);
		t_sample feedforward = ((allpassinput * gain) * (-((t_sample)0.5)));
		t_sample allpassoutput = (allpassread + feedforward);
		m_allpass_96.write(allpassinput);
		return allpassoutput;
		
	};
	inline t_sample allpass_d_d_d_97(t_sample input, t_sample time, t_sample gain) {
		t_sample allpassread = m_allpass_98.read_linear((time * (samplerate * 0.001)));
		t_sample feedback = ((allpassread * gain) * ((t_sample)0.5));
		t_sample allpassinput = (input + feedback);
		t_sample feedforward = ((allpassinput * gain) * (-((t_sample)0.5)));
		t_sample allpassoutput = (allpassread + feedforward);
		m_allpass_98.write(allpassinput);
		return allpassoutput;
		
	};
	inline t_sample allpass_d_d_d_99(t_sample input, t_sample time, t_sample gain) {
		t_sample allpassread = m_allpass_100.read_linear((time * (samplerate * 0.001)));
		t_sample feedback = ((allpassread * gain) * ((t_sample)0.5));
		t_sample allpassinput = (input + feedback);
		t_sample feedforward = ((allpassinput * gain) * (-((t_sample)0.5)));
		t_sample allpassoutput = (allpassread + feedforward);
		m_allpass_100.write(allpassinput);
		return allpassoutput;
		
	};
	inline t_sample allpass_d_d_d_101(t_sample input, t_sample time, t_sample gain) {
		t_sample allpassread = m_allpass_102.read_linear((time * (samplerate * 0.001)));
		t_sample feedback = ((allpassread * gain) * ((t_sample)0.5));
		t_sample allpassinput = (input + feedback);
		t_sample feedforward = ((allpassinput * gain) * (-((t_sample)0.5)));
		t_sample allpassoutput = (allpassread + feedforward);
		m_allpass_102.write(allpassinput);
		return allpassoutput;
		
	};
	inline t_sample allpass_d_d_d_103(t_sample input, t_sample time, t_sample gain) {
		t_sample allpassread = m_allpass_104.read_linear((time * (samplerate * 0.001)));
		t_sample feedback = ((allpassread * gain) * ((t_sample)0.5));
		t_sample allpassinput = (input + feedback);
		t_sample feedforward = ((allpassinput * gain) * (-((t_sample)0.5)));
		t_sample allpassoutput = (allpassread + feedforward);
		m_allpass_104.write(allpassinput);
		return allpassoutput;
		
	};
	inline t_sample allpass_d_d_d_105(t_sample input, t_sample time, t_sample gain) {
		t_sample allpassread = m_allpass_106.read_linear((time * (samplerate * 0.001)));
		t_sample feedback = ((allpassread * gain) * ((t_sample)0.5));
		t_sample allpassinput = (input + feedback);
		t_sample feedforward = ((allpassinput * gain) * (-((t_sample)0.5)));
		t_sample allpassoutput = (allpassread + feedforward);
		m_allpass_106.write(allpassinput);
		return allpassoutput;
		
	};
	inline t_sample allpass_d_d_d_107(t_sample input, t_sample time, t_sample gain) {
		t_sample allpassread = m_allpass_108.read_linear((time * (samplerate * 0.001)));
		t_sample feedback = ((allpassread * gain) * ((t_sample)0.5));
		t_sample allpassinput = (input + feedback);
		t_sample feedforward = ((allpassinput * gain) * (-((t_sample)0.5)));
		t_sample allpassoutput = (allpassread + feedforward);
		m_allpass_108.write(allpassinput);
		return allpassoutput;
		
	};
	inline t_sample allpass_d_d_d_109(t_sample input, t_sample time, t_sample gain) {
		t_sample allpassread = m_allpass_110.read_linear((time * (samplerate * 0.001)));
		t_sample feedback = ((allpassread * gain) * ((t_sample)0.5));
		t_sample allpassinput = (input + feedback);
		t_sample feedforward = ((allpassinput * gain) * (-((t_sample)0.5)));
		t_sample allpassoutput = (allpassread + feedforward);
		m_allpass_110.write(allpassinput);
		return allpassoutput;
		
	};
	inline t_sample allpass_d_d_d_111(t_sample input, t_sample time, t_sample gain) {
		t_sample allpassread = m_allpass_112.read_linear((time * (samplerate * 0.001)));
		t_sample feedback = ((allpassread * gain) * ((t_sample)0.5));
		t_sample allpassinput = (input + feedback);
		t_sample feedforward = ((allpassinput * gain) * (-((t_sample)0.5)));
		t_sample allpassoutput = (allpassread + feedforward);
		m_allpass_112.write(allpassinput);
		return allpassoutput;
		
	};
	inline t_sample allpass_d_d_d_113(t_sample input, t_sample time, t_sample gain) {
		t_sample allpassread = m_allpass_114.read_linear((time * (samplerate * 0.001)));
		t_sample feedback = ((allpassread * gain) * ((t_sample)0.5));
		t_sample allpassinput = (input + feedback);
		t_sample feedforward = ((allpassinput * gain) * (-((t_sample)0.5)));
		t_sample allpassoutput = (allpassread + feedforward);
		m_allpass_114.write(allpassinput);
		return allpassoutput;
		
	};
	inline t_sample allpass_d_d_d_115(t_sample input, t_sample time, t_sample gain) {
		t_sample allpassread = m_allpass_116.read_linear((time * (samplerate * 0.001)));
		t_sample feedback = ((allpassread * gain) * ((t_sample)0.5));
		t_sample allpassinput = (input + feedback);
		t_sample feedforward = ((allpassinput * gain) * (-((t_sample)0.5)));
		t_sample allpassoutput = (allpassread + feedforward);
		m_allpass_116.write(allpassinput);
		return allpassoutput;
		
	};
	inline t_sample allpass_d_d_d_117(t_sample input, t_sample time, t_sample gain) {
		t_sample allpassread = m_allpass_118.read_linear((time * (samplerate * 0.001)));
		t_sample feedback = ((allpassread * gain) * ((t_sample)0.5));
		t_sample allpassinput = (input + feedback);
		t_sample feedforward = ((allpassinput * gain) * (-((t_sample)0.5)));
		t_sample allpassoutput = (allpassread + feedforward);
		m_allpass_118.write(allpassinput);
		return allpassoutput;
		
	};
	inline t_sample allpass_d_d_d_119(t_sample input, t_sample time, t_sample gain) {
		t_sample allpassread = m_allpass_120.read_linear((time * (samplerate * 0.001)));
		t_sample feedback = ((allpassread * gain) * ((t_sample)0.5));
		t_sample allpassinput = (input + feedback);
		t_sample feedforward = ((allpassinput * gain) * (-((t_sample)0.5)));
		t_sample allpassoutput = (allpassread + feedforward);
		m_allpass_120.write(allpassinput);
		return allpassoutput;
		
	};
	inline t_sample allpass_d_d_d_121(t_sample input, t_sample time, t_sample gain) {
		t_sample allpassread = m_allpass_122.read_linear((time * (samplerate * 0.001)));
		t_sample feedback = ((allpassread * gain) * ((t_sample)0.5));
		t_sample allpassinput = (input + feedback);
		t_sample feedforward = ((allpassinput * gain) * (-((t_sample)0.5)));
		t_sample allpassoutput = (allpassread + feedforward);
		m_allpass_122.write(allpassinput);
		return allpassoutput;
		
	};
	inline t_sample allpass_d_d_d_123(t_sample input, t_sample time, t_sample gain) {
		t_sample allpassread = m_allpass_124.read_linear((time * (samplerate * 0.001)));
		t_sample feedback = ((allpassread * gain) * ((t_sample)0.5));
		t_sample allpassinput = (input + feedback);
		t_sample feedforward = ((allpassinput * gain) * (-((t_sample)0.5)));
		t_sample allpassoutput = (allpassread + feedforward);
		m_allpass_124.write(allpassinput);
		return allpassoutput;
		
	};
	inline void biquad_d_d_i_d_d_i(t_sample xL, t_sample xR, int cf, t_sample gain, t_sample Q, int mode, t_sample& out1, t_sample& out2) {
		t_sample a0 = ((int)0);
		t_sample a1 = ((int)0);
		t_sample a2 = ((int)0);
		t_sample b1 = ((int)0);
		t_sample b2 = ((int)0);
		t_sample omega = safediv((cf * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn = sin(omega);
		t_sample cs = cos(omega);
		t_sample A = sqrt(gain);
		t_sample beta = sqrt((safediv(((A * A) + ((int)1)), Q) - ((A - ((int)1)) * (A - ((int)1)))));
		if ((mode == ((int)0))) {
			t_sample b0 = safediv(((int)1), (((A + ((int)1)) + ((A - ((int)1)) * cs)) + (beta * sn)));
			a0 = ((A * (((A + ((int)1)) - ((A - ((int)1)) * cs)) + (beta * sn))) * b0);
			a1 = (((((int)2) * A) * ((A - ((int)1)) - ((A + ((int)1)) * cs))) * b0);
			a2 = ((A * (((A + ((int)1)) - ((A - ((int)1)) * cs)) - (beta * sn))) * b0);
			b1 = (((-((int)2)) * ((A - ((int)1)) + ((A + ((int)1)) * cs))) * b0);
			b2 = ((((A + ((int)1)) + ((A - ((int)1)) * cs)) - (beta * sn)) * b0);
			
		};
		if ((mode == ((int)1))) {
			t_sample b0 = safediv(((int)1), (((A + ((int)1)) - ((A - ((int)1)) * cs)) + (beta * sn)));
			a0 = ((A * (((A + ((int)1)) + ((A - ((int)1)) * cs)) + (beta * sn))) * b0);
			a1 = ((((-((int)2)) * A) * ((A - ((int)1)) + ((A + ((int)1)) * cs))) * b0);
			a2 = ((A * (((A + ((int)1)) + ((A - ((int)1)) * cs)) - (beta * sn))) * b0);
			b1 = ((((int)2) * ((A - ((int)1)) - ((A + ((int)1)) * cs))) * b0);
			b2 = ((((A + ((int)1)) - ((A - ((int)1)) * cs)) - (beta * sn)) * b0);
			
		};
		t_sample yL = ((xL * a0) + m_z1L_128);
		m_z1L_128 = (((xL * a1) + m_z2L_127) - (b1 * yL));
		m_z2L_127 = ((xL * a2) - (b2 * yL));
		t_sample yR = ((xR * a0) + m_z1R_126);
		m_z1R_126 = (((xR * a1) + m_z2R_125) - (b1 * yR));
		m_z2R_125 = ((xR * a2) - (b2 * yR));
		out1 = yL;
		out2 = yR;
		
	};
	inline void biquad_d_d_i_d_d_i_131(t_sample xL, t_sample xR, int cf, t_sample gain, t_sample Q, int mode, t_sample& out1, t_sample& out2) {
		t_sample a0 = ((int)0);
		t_sample a1 = ((int)0);
		t_sample a2 = ((int)0);
		t_sample b1 = ((int)0);
		t_sample b2 = ((int)0);
		t_sample omega = safediv((cf * ((t_sample)6.2831853071796)), samplerate);
		t_sample sn = sin(omega);
		t_sample cs = cos(omega);
		t_sample A = sqrt(gain);
		t_sample beta = sqrt((safediv(((A * A) + ((int)1)), Q) - ((A - ((int)1)) * (A - ((int)1)))));
		if ((mode == ((int)0))) {
			t_sample b0 = safediv(((int)1), (((A + ((int)1)) + ((A - ((int)1)) * cs)) + (beta * sn)));
			a0 = ((A * (((A + ((int)1)) - ((A - ((int)1)) * cs)) + (beta * sn))) * b0);
			a1 = (((((int)2) * A) * ((A - ((int)1)) - ((A + ((int)1)) * cs))) * b0);
			a2 = ((A * (((A + ((int)1)) - ((A - ((int)1)) * cs)) - (beta * sn))) * b0);
			b1 = (((-((int)2)) * ((A - ((int)1)) + ((A + ((int)1)) * cs))) * b0);
			b2 = ((((A + ((int)1)) + ((A - ((int)1)) * cs)) - (beta * sn)) * b0);
			
		};
		if ((mode == ((int)1))) {
			t_sample b0 = safediv(((int)1), (((A + ((int)1)) - ((A - ((int)1)) * cs)) + (beta * sn)));
			a0 = ((A * (((A + ((int)1)) + ((A - ((int)1)) * cs)) + (beta * sn))) * b0);
			a1 = ((((-((int)2)) * A) * ((A - ((int)1)) + ((A + ((int)1)) * cs))) * b0);
			a2 = ((A * (((A + ((int)1)) + ((A - ((int)1)) * cs)) - (beta * sn))) * b0);
			b1 = ((((int)2) * ((A - ((int)1)) - ((A + ((int)1)) * cs))) * b0);
			b2 = ((((A + ((int)1)) - ((A - ((int)1)) * cs)) - (beta * sn)) * b0);
			
		};
		t_sample yL = ((xL * a0) + m_z1L_135);
		m_z1L_135 = (((xL * a1) + m_z2L_134) - (b1 * yL));
		m_z2L_134 = ((xL * a2) - (b2 * yL));
		t_sample yR = ((xR * a0) + m_z1R_133);
		m_z1R_133 = (((xR * a1) + m_z2R_132) - (b1 * yR));
		m_z2R_132 = ((xR * a2) - (b2 * yR));
		out1 = yL;
		out2 = yR;
		
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 1;
int gen_kernel_numouts = 2;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 9; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1" };
const char *gen_kernel_outnames[] = { "out1", "out2" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_reverse(value); break;
		case 1: self->set_size(value); break;
		case 2: self->set_speed(value); break;
		case 3: self->set_depth(value); break;
		case 4: self->set_predelay(value); break;
		case 5: self->set_tilt(value); break;
		case 6: self->set_absorb(value); break;
		case 7: self->set_decay(value); break;
		case 8: self->set_mix(value); break;

		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_reverse_9; break;
		case 1: *value = self->m_size_8; break;
		case 2: *value = self->m_speed_7; break;
		case 3: *value = self->m_depth_6; break;
		case 4: *value = self->m_predelay_5; break;
		case 5: *value = self->m_tilt_4; break;
		case 6: *value = self->m_absorb_3; break;
		case 7: *value = self->m_decay_2; break;
		case 8: *value = self->m_mix_1; break;

		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(9 * sizeof(ParamInfo));
	self->__commonstate.numparams = 9;
	// initialize parameter 0 ("m_reverse_9")
	pi = self->__commonstate.params + 0;
	pi->name = "reverse";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_reverse_9;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_size_8")
	pi = self->__commonstate.params + 1;
	pi->name = "size";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_size_8;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 1;
	pi->outputmax = 500;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_speed_7")
	pi = self->__commonstate.params + 2;
	pi->name = "speed";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_speed_7;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0.1;
	pi->outputmax = 256;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_depth_6")
	pi = self->__commonstate.params + 3;
	pi->name = "depth";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_depth_6;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -100;
	pi->outputmax = 100;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_predelay_5")
	pi = self->__commonstate.params + 4;
	pi->name = "predelay";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_predelay_5;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 7;
	pi->outputmax = 500;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_tilt_4")
	pi = self->__commonstate.params + 5;
	pi->name = "tilt";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_tilt_4;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = -100;
	pi->outputmax = 100;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_absorb_3")
	pi = self->__commonstate.params + 6;
	pi->name = "absorb";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_absorb_3;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 100;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_decay_2")
	pi = self->__commonstate.params + 7;
	pi->name = "decay";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_decay_2;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 120;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_mix_1")
	pi = self->__commonstate.params + 8;
	pi->name = "mix";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_mix_1;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 100;
	pi->exp = 0;
	pi->units = "";		// no units defined

	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);

	delete self;
}


} // gen_exported::
